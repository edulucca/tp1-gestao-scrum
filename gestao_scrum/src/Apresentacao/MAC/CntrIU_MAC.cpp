#include "CntrIU_MAC.hpp"
#include "MAC_Commands.hpp"
#include "Email.hpp"
#include "Nome.hpp"
#include "Senha.hpp"
#include "Papel.hpp"
#include "Invoker.hpp"
#include "EntradaUsuario.hpp"

#include <iostream>
#include <memory>

using namespace std;

CntrIU_MAC::CntrIU_MAC() : cntrMSCCadastroService(nullptr) {}

void CntrIU_MAC::setCntrMSCCadastroService(IMSC_CadastroService* cntrMSCCadastroService) {
    this->cntrMSCCadastroService = cntrMSCCadastroService;
}

static string lerEmail(bool permitirCancelar) {
    while (true) {
        cout << "  Padrao de email: parte-local@dominio (ex: luis.serra@unb.br)" << endl;
        string entrada = EntradaUsuario::lerPalavra("Digite o email", permitirCancelar);
        try {
            Email emailDom;
            emailDom.setEmail(entrada);
            return emailDom.getEmail();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerNome(bool permitirCancelar) {
    while (true) {
        string entrada = EntradaUsuario::lerLinha("Digite o nome", true, permitirCancelar);
        try {
            Nome nomeDom;
            nomeDom.setNome(entrada);
            return nomeDom.getNome();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerSenha(bool permitirCancelar) {
    while (true) {
        cout << "  Padrao de senha: 6 caracteres alternando letra e digito (ex: a1B2c3)" << endl;
        string entrada = EntradaUsuario::lerPalavra("Digite a senha", permitirCancelar);
        try {
            Senha senhaDom;
            senhaDom.setSenha(entrada);
            return senhaDom.getSenha();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerPapel(bool permitirCancelar) {
    while (true) {
        cout << "  Papeis validos: DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO" << endl;
        string entrada = EntradaUsuario::lerLinha("Digite o papel", true, permitirCancelar);
        try {
            Papel papelDom;
            papelDom.setPapel(entrada);
            return papelDom.getPapel();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static bool executarCriarPessoa(IMSC_CadastroService* servico) {
    cout << endl << "Cadastro de pessoa." << endl;
    cout << "Digite 0 em qualquer campo para cancelar o cadastro." << endl << endl;

    string emailStr = lerEmail(true);
    string nomeStr = lerNome(true);
    string senhaStr = lerSenha(true);
    string papelStr = lerPapel(true);

    Pessoa pessoa;
    pessoa.setEmail(emailStr);
    pessoa.setNome(nomeStr);
    pessoa.setSenha(senhaStr);
    pessoa.setPapel(papelStr);

    bool resultado = false;
    Invoker invoker;
    invoker.addCommand(make_shared<CriarPessoaCommand>(servico, &pessoa, &resultado));
    invoker.runAll();
    return resultado;
}

bool CntrIU_MAC::executarServico(int servicoId, const string& emailUsuario) {
    switch (servicoId) {
        case 1:
            return executarCriarPessoa(cntrMSCCadastroService);
        case 2: {
            PessoaResumo resumo;
            if (cntrMSCCadastroService->lerPessoa(emailUsuario, resumo)) {
                cout << endl << "Meus dados:" << endl;
                cout << "  Email: " << resumo.email << endl;
                cout << "  Nome: " << resumo.nome << endl;
                cout << "  Papel: " << resumo.papel << endl;
                return true;
            }
            cout << endl << "Dados nao encontrados." << endl;
            return false;
        }
        case 3: {
            PessoaResumo existente;
            if (!cntrMSCCadastroService->lerPessoa(emailUsuario, existente)) {
                cout << endl << "Dados nao encontrados." << endl;
                return false;
            }
            cout << endl << "Atualizar meus dados." << endl;
            cout << "Nome atual: " << existente.nome << endl;
            cout << "Papel atual: " << existente.papel << endl;
            string novoNome = lerNome(false);
            string novoPapel = lerPapel(false);
            return cntrMSCCadastroService->atualizarPessoa(emailUsuario, novoNome, novoPapel);
        }
        case 4: {
            string email = lerEmail(false);
            if (cntrMSCCadastroService->excluirPessoa(email)) {
                cout << endl << "Pessoa excluida com sucesso." << endl;
                return true;
            }
            cout << endl << "Pessoa nao encontrada." << endl;
            return false;
        }
        default:
            cout << endl << "Servico de pessoa invalido." << endl;
            return false;
    }
}
