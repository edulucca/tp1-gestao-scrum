/**
 * @file main_cli.cpp
 * @brief Ponto de entrada da aplicacao — monta stubs, controladoras e loop principal.
 */
#include "CntrIU_MAA.hpp"
#include "CntrIU_MAC.hpp"
#include "CntrIU_MAG.hpp"
#include "MSA_AuthServiceStub.hpp"
#include "MSC_CadastroServiceStub.hpp"
#include "MSG_GestaoServiceStub.hpp"
#include "ServicoAutorizacao.hpp"
#include "EntradaUsuario.hpp"

#include <iostream>
#include <vector>

using namespace std;

static void exibirMenuInicial() {
    cout << endl << "=== Gestao Scrum ===" << endl;
    cout << "1 - Cadastrar novo usuario" << endl;
    cout << "2 - Autenticar" << endl;
    cout << "0 - Sair" << endl;
}

static vector<int> montarServicosAutorizados(const string& papel) {
    vector<int> servicos;
    for (int id = 1; id <= ServicoAutorizacao::TOTAL_SERVICOS; ++id) {
        if (ServicoAutorizacao::podeExecutar(id, papel)) {
            servicos.push_back(id);
        }
    }
    return ServicoAutorizacao::ordenarPorSecao(servicos);
}

static void exibirMenuAutenticado(const string& papel, const vector<int>& servicos) {
    cout << endl << "=== Gestao Scrum ===" << endl;
    cout << "Papel: " << papel << endl << endl;

    string secaoAtual;
    for (size_t i = 0; i < servicos.size(); ++i) {
        string secao = ServicoAutorizacao::obterSecao(servicos[i]);
        if (!secao.empty() && secao != secaoAtual) {
            cout << "==== " << secao << " ====" << endl << endl;
            secaoAtual = secao;
        }
        cout << (i + 1) << " - " << ServicoAutorizacao::obterDescricao(servicos[i]) << endl;
    }

    cout << endl << (servicos.size() + 1) << " - Logout" << endl;
    cout << "0 - Sair" << endl;
}

int main() {
    MSC_CadastroServiceStub mscStub;
    MSA_AuthServiceStub msaStub;
    MSG_GestaoServiceStub msgStub;

    msaStub.setCadastroService(&mscStub);

    CntrIU_MAA cntrMAA;
    CntrIU_MAC cntrMAC;
    CntrIU_MAG cntrMAG;

    cntrMAA.setCntrMSAAuthService(&msaStub);
    cntrMAC.setCntrMSCCadastroService(&mscStub);
    cntrMAG.setCntrMSGGestaoService(&msgStub);

    bool autenticado = false;
    string nomeUsuarioLogado;
    string emailUsuarioLogado;
    string papelUsuarioLogado;
    vector<int> servicosAutorizados;
    int opcao = 0;

    while (true) {
        if (autenticado) {
            exibirMenuAutenticado(papelUsuarioLogado, servicosAutorizados);
        } else {
            exibirMenuInicial();
        }

        cout << "Opcao: ";
        if (!(cin >> opcao)) {
            cin.clear();
            EntradaUsuario::limparBuffer();
            cout << endl << "Entrada interrompida." << endl;
            break;
        }

        if (opcao == 0) {
            break;
        }

        try {
            if (!autenticado) {
                switch (opcao) {
                    case 1: {
                        if (cntrMAC.executarServico(1)) {
                            cout << endl << "Usuario cadastrado com sucesso." << endl;
                            cout << "Faca autenticacao para acessar as demais funcoes." << endl;
                        } else {
                            cout << endl << "Erro no cadastro: email ja cadastrado ou operacao recusada." << endl;
                        }
                        break;
                    }
                    case 2: {
                        string nome;
                        string papel;
                        string email;
                        if (cntrMAA.login(nome, papel, email)) {
                            autenticado = true;
                            nomeUsuarioLogado = nome;
                            papelUsuarioLogado = papel;
                            emailUsuarioLogado = email;
                            servicosAutorizados = montarServicosAutorizados(papelUsuarioLogado);
                            cout << endl << "Bem-Vindo (a), " << nomeUsuarioLogado << endl;
                        } else {
                            cout << endl << "Erro autenticacao: email ou senha invalidos." << endl;
                        }
                        break;
                    }
                    default:
                        cout << endl << "Opcao invalida." << endl;
                        break;
                }
            } else {
                if (opcao == static_cast<int>(servicosAutorizados.size() + 1)) {
                    cntrMAA.logout();
                    autenticado = false;
                    nomeUsuarioLogado.clear();
                    emailUsuarioLogado.clear();
                    papelUsuarioLogado.clear();
                    servicosAutorizados.clear();
                    continue;
                }

                if (opcao < 1 || opcao > static_cast<int>(servicosAutorizados.size())) {
                    cout << endl << "Opcao invalida." << endl;
                    continue;
                }

                int servicoId = servicosAutorizados[static_cast<size_t>(opcao - 1)];
                bool sucesso = false;

                if (servicoId >= 1 && servicoId <= 4) {
                    sucesso = cntrMAC.executarServico(servicoId, emailUsuarioLogado);
                } else {
                    sucesso = cntrMAG.executarServico(servicoId, emailUsuarioLogado);
                }

                if (sucesso) {
                    cout << endl << "Operacao concluida com sucesso." << endl;
                } else {
                    cout << endl << "Operacao nao concluida." << endl;
                }
            }
        } catch (const EntradaCancelada&) {
            cout << endl << "Cadastro cancelado." << endl;
        } catch (const runtime_error&) {
            cout << endl << "Erro de sistema." << endl;
        }
    }

    return 0;
}
