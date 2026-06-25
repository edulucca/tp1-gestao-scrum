#include "CntrIU_MAG.hpp"
#include "Codigo.hpp"
#include "Data.hpp"
#include "Email.hpp"
#include "Estado.hpp"
#include "Nome.hpp"
#include "Texto.hpp"
#include "Tempo.hpp"
#include "Prioridade.hpp"
#include "EntradaUsuario.hpp"

#include <iostream>
#include <string>

using namespace std;

CntrIU_MAG::CntrIU_MAG() : cntrMSGGestaoService(nullptr) {}

void CntrIU_MAG::setCntrMSGGestaoService(IMSG_GestaoService* cntrMSGGestaoService) {
    this->cntrMSGGestaoService = cntrMSGGestaoService;
}

static string lerCodigo(const string& rotulo, bool exibirPadrao, bool permitirCancelar) {
    if (exibirPadrao) {
        cout << "  Padrao de codigo: 2 letras maiusculas + 3 digitos (ex: AB123)" << endl;
    }
    while (true) {
        string entrada = EntradaUsuario::lerPalavra(rotulo, permitirCancelar);
        try {
            Codigo codigo;
            codigo.setCodigo(entrada);
            return codigo.getCodigo();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerEmail(bool permitirCancelar) {
    while (true) {
        string entrada = EntradaUsuario::lerPalavra("Digite o email", permitirCancelar);
        try {
            Email email;
            email.setEmail(entrada);
            return email.getEmail();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerEstado() {
    while (true) {
        string entrada = EntradaUsuario::lerLinha("Digite o estado", true, false);
        try {
            Estado estado;
            estado.setEstado(entrada);
            return estado.getEstado();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerNomeComValidacao(const string& rotulo, bool limparBufferAntes, bool permitirCancelar) {
    while (true) {
        string entrada = EntradaUsuario::lerLinha(rotulo, limparBufferAntes, permitirCancelar);
        try {
            Nome nomeDom;
            nomeDom.setNome(entrada);
            return nomeDom.getNome();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerTextoComValidacao(const string& rotulo, bool limparBufferAntes, bool permitirCancelar) {
    while (true) {
        string entrada = EntradaUsuario::lerLinha(rotulo, limparBufferAntes, permitirCancelar);
        try {
            Texto texto;
            texto.setTexto(entrada);
            return texto.getTexto();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerDataComValidacao(const string& rotulo, bool permitirCancelar) {
    while (true) {
        cout << "  Padrao de data: DD/MM/AAAA (ex: 15/10/2024)" << endl;
        string entrada = EntradaUsuario::lerLinha(rotulo, true, permitirCancelar);
        try {
            Data data;
            data.setData(entrada);
            return data.getData();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static int lerTempoComValidacao(const string& rotulo, bool limparBufferAntes, bool permitirCancelar) {
    while (true) {
        int valor = EntradaUsuario::lerInteiro(rotulo, limparBufferAntes, permitirCancelar);
        try {
            Tempo tempo;
            tempo.setTempo(valor);
            return tempo.getTempo();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static string lerPrioridadeComValidacao(const string& rotulo, bool limparBufferAntes, bool permitirCancelar) {
    while (true) {
        string entrada = EntradaUsuario::lerLinha(rotulo, limparBufferAntes, permitirCancelar);
        try {
            Prioridade pri;
            pri.setPrioridade(entrada);
            return pri.getPrioridade();
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }
}

static void exibirHistorias(const vector<HistoriaUsuario*>& historias) {
    if (historias.empty()) {
        cout << endl << "Nenhuma historia encontrada." << endl;
        return;
    }
    cout << endl << "Historias encontradas:" << endl;
    for (size_t i = 0; i < historias.size(); ++i) {
        cout << "  " << historias[i]->getCodigo()
             << " - " << historias[i]->getTitulo()
             << " [" << historias[i]->getEstado() << "]" << endl;
    }
}

static void exibirProjetos(const vector<ProjetoResumo>& projetos, const string& titulo) {
    if (projetos.empty()) {
        cout << endl << "Nenhum projeto encontrado." << endl;
        return;
    }
    cout << endl << titulo << endl;
    for (size_t i = 0; i < projetos.size(); ++i) {
        cout << "  " << projetos[i].codigo << " - " << projetos[i].nome << endl;
    }
}

bool CntrIU_MAG::executarServico(int servicoId, const string& emailUsuario) {
    switch (servicoId) {
        case 5: {
            cout << endl << "Cadastro de projeto." << endl;
            cout << "Digite 0 em qualquer campo para cancelar o cadastro." << endl << endl;
            string codigo = lerCodigo("Digite o codigo do projeto", true, true);
            string nome = lerNomeComValidacao("Digite o nome do projeto", true, true);
            string inicio = lerDataComValidacao("Digite a data de inicio", true);
            string termino = lerDataComValidacao("Digite a data de termino", true);
            Projeto projeto;
            projeto.setCodigo(codigo);
            projeto.setNome(nome);
            projeto.setDataInicio(inicio);
            projeto.setDataTermino(termino);
            return cntrMSGGestaoService->criarProjeto(projeto, emailUsuario);
        }
        case 6: {
            string codigo = lerCodigo("Digite o codigo do projeto", true, false);
            ProjetoResumo resumo;
            if (cntrMSGGestaoService->lerProjeto(codigo, resumo)) {
                cout << endl << "Projeto encontrado:" << endl;
                cout << "  Codigo: " << resumo.codigo << endl;
                cout << "  Nome: " << resumo.nome << endl;
                cout << "  Data inicio: " << resumo.dataInicio << endl;
                cout << "  Data termino: " << resumo.dataTermino << endl;
                return true;
            }
            cout << endl << "Projeto nao encontrado." << endl;
            return false;
        }
        case 7: {
            string codigo = lerCodigo("Digite o codigo do projeto", true, false);
            string nome = lerNomeComValidacao("Digite o novo nome", true, false);
            return cntrMSGGestaoService->atualizarProjeto(codigo, nome);
        }
        case 8: {
            string codigo = lerCodigo("Digite o codigo do projeto", true, false);
            return cntrMSGGestaoService->excluirProjeto(codigo);
        }
        case 9: {
            cout << endl << "Cadastro de plano de sprint." << endl;
            cout << "Digite 0 em qualquer campo para cancelar o cadastro." << endl << endl;
            string codigoProjeto = lerCodigo("Digite o codigo do projeto", true, true);
            string codigoPlano = lerCodigo("Digite o codigo do plano", true, true);
            string objetivo = lerTextoComValidacao("Digite o objetivo", true, true);
            int capacidade = lerTempoComValidacao("Digite a capacidade (dias)", false, true);
            PlanoSprint plano;
            plano.setCodigo(codigoPlano);
            plano.setObjetivo(objetivo);
            plano.setCapacidade(capacidade);
            return cntrMSGGestaoService->criarPlanoSprint(plano, codigoProjeto);
        }
        case 10: {
            string codigo = lerCodigo("Digite o codigo do plano", true, false);
            PlanoResumo resumo;
            if (cntrMSGGestaoService->lerPlanoSprint(codigo, resumo)) {
                cout << endl << "Plano: " << resumo.codigo << " - " << resumo.objetivo
                     << " (" << resumo.capacidade << " dias)" << endl;
                return true;
            }
            cout << endl << "Plano nao encontrado." << endl;
            return false;
        }
        case 11: {
            string codigo = lerCodigo("Digite o codigo do plano", true, false);
            string objetivo = lerTextoComValidacao("Digite o novo objetivo", true, false);
            int capacidade = lerTempoComValidacao("Digite a nova capacidade", false, false);
            return cntrMSGGestaoService->atualizarPlanoSprint(codigo, objetivo, capacidade);
        }
        case 12: {
            string codigo = lerCodigo("Digite o codigo do plano", true, false);
            return cntrMSGGestaoService->excluirPlanoSprint(codigo);
        }
        case 13: {
            cout << endl << "Cadastro de historia de usuario." << endl;
            cout << "Digite 0 em qualquer campo para cancelar o cadastro." << endl << endl;
            string codigoProjeto = lerCodigo("Digite o codigo do projeto", true, true);
            string codigo = lerCodigo("Digite o codigo da historia", true, true);
            string titulo = lerTextoComValidacao("Digite o titulo", true, true);
            string papel = lerTextoComValidacao("Digite o papel (como)", false, true);
            string acao = lerTextoComValidacao("Digite a acao (eu quero)", false, true);
            string valor = lerTextoComValidacao("Digite o valor (para)", false, true);
            int estimativa = lerTempoComValidacao("Digite a estimativa (dias)", false, true);
            string prioridade = lerPrioridadeComValidacao("Digite a prioridade", false, true);
            HistoriaUsuario historia;
            historia.setCodigo(codigo);
            historia.setTitulo(titulo);
            historia.setPapel(papel);
            historia.setAcao(acao);
            historia.setValor(valor);
            historia.setEstimativa(estimativa);
            historia.setPrioridade(prioridade);
            return cntrMSGGestaoService->criarHistoria(historia, codigoProjeto);
        }
        case 14: {
            string codigo = lerCodigo("Digite o codigo da historia", true, false);
            HistoriaUsuario* historia = cntrMSGGestaoService->lerHistoria(codigo);
            if (historia == nullptr) {
                cout << endl << "Historia nao encontrada." << endl;
                return false;
            }
            cout << endl << historia->getCodigo() << " - " << historia->getTitulo()
                 << " [" << historia->getEstado() << "]" << endl;
            return true;
        }
        case 15: {
            string codigo = lerCodigo("Digite o codigo da historia", true, false);
            HistoriaUsuario* existente = cntrMSGGestaoService->lerHistoria(codigo);
            if (existente == nullptr) {
                cout << endl << "Historia nao encontrada." << endl;
                return false;
            }
            string titulo = lerTextoComValidacao("Digite o novo titulo", true, false);
            existente->setTitulo(titulo);
            return cntrMSGGestaoService->atualizarHistoria(*existente);
        }
        case 16: {
            string codigo = lerCodigo("Digite o codigo da historia", true, false);
            return cntrMSGGestaoService->excluirHistoria(codigo);
        }
        case 17: {
            string codigoHistoria = lerCodigo("Digite o codigo da historia", true, false);
            string email = lerEmail(false);
            return cntrMSGGestaoService->associarHistoriaPessoa(codigoHistoria, email);
        }
        case 18: {
            string codigoHistoria = lerCodigo("Digite o codigo da historia", true, false);
            string email = lerEmail(false);
            return cntrMSGGestaoService->removerAssociacaoHistoriaPessoa(codigoHistoria, email);
        }
        case 19: {
            exibirProjetos(
                cntrMSGGestaoService->listarProjetosPorPessoa(emailUsuario),
                "Meus projetos:");
            return true;
        }
        case 20: {
            string codigo = lerCodigo("Digite o codigo do projeto", true, false);
            exibirHistorias(cntrMSGGestaoService->listarHistoriasPorProjeto(codigo));
            return true;
        }
        case 21: {
            string codigo = lerCodigo("Digite o codigo do projeto", true, false);
            vector<PlanoResumo> planos = cntrMSGGestaoService->listarPlanosPorProjeto(codigo);
            if (planos.empty()) {
                cout << endl << "Nenhum plano encontrado." << endl;
            } else {
                cout << endl << "Planos do projeto:" << endl;
                for (size_t i = 0; i < planos.size(); ++i) {
                    cout << "  " << planos[i].codigo << " - " << planos[i].objetivo << endl;
                }
            }
            return true;
        }
        case 22: {
            string codigo = lerCodigo("Digite o codigo do plano", true, false);
            exibirHistorias(cntrMSGGestaoService->listarHistoriasPorPlano(codigo));
            return true;
        }
        case 23: {
            string email = lerEmail(false);
            exibirHistorias(cntrMSGGestaoService->listarHistoriasPorPessoa(email));
            return true;
        }
        case 24: {
            string codigoHistoria = lerCodigo("Digite o codigo da historia", true, false);
            string codigoPlano = lerCodigo("Digite o codigo do plano", true, false);
            return cntrMSGGestaoService->moverHistoriaParaPlano(codigoHistoria, codigoPlano);
        }
        case 25: {
            string codigo = lerCodigo("Digite o codigo da historia", true, false);
            string estado = lerEstado();
            return cntrMSGGestaoService->alterarEstadoHistoria(codigo, estado);
        }
        case 26: {
            exibirProjetos(cntrMSGGestaoService->listarProjetos(), "Projetos cadastrados:");
            return true;
        }
        default:
            cout << endl << "Servico de gestao invalido." << endl;
            return false;
    }
}
