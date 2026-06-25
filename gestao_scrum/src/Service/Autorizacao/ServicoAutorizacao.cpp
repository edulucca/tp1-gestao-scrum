#include "ServicoAutorizacao.hpp"

using namespace std;

static bool papelEm(const string& papel, const string& a, const string& b, const string& c) {
    return papel == a || papel == b || papel == c;
}

static bool papelEm(const string& papel, const string& a, const string& b) {
    return papel == a || papel == b;
}

bool ServicoAutorizacao::podeExecutar(int servicoId, const string& papel) {
    const string PP = "PROPRIETARIO DE PRODUTO";
    const string MS = "MESTRE SCRUM";
    const string DEV = "DESENVOLVEDOR";

    switch (servicoId) {
        case 1:
            return false;
        case 2: case 3: case 4:
        case 6: case 10: case 14:
        case 19: case 20: case 21: case 22: case 23: case 26:
            return papelEm(papel, PP, MS, DEV);
        case 5: case 7: case 8: case 13: case 15: case 16:
            return papel == PP;
        case 9: case 11: case 12: case 17: case 18: case 24:
            return papel == MS;
        case 25:
            return papelEm(papel, PP, MS);
        default:
            return false;
    }
}

string ServicoAutorizacao::obterDescricao(int servicoId) {
    switch (servicoId) {
        case 1: return "Criar pessoa";
        case 2: return "Meus dados";
        case 3: return "Atualizar meus dados";
        case 4: return "Excluir pessoa";
        case 5: return "Criar projeto";
        case 6: return "Ler projeto";
        case 7: return "Atualizar projeto";
        case 8: return "Excluir projeto";
        case 9: return "Criar plano de sprint";
        case 10: return "Ler plano de sprint";
        case 11: return "Atualizar plano de sprint";
        case 12: return "Excluir plano de sprint";
        case 13: return "Criar historia de usuario";
        case 14: return "Ler historia de usuario";
        case 15: return "Atualizar historia de usuario";
        case 16: return "Excluir historia de usuario";
        case 17: return "Associar historia a pessoa";
        case 18: return "Remover associacao historia-pessoa";
        case 19: return "Listar meus projetos";
        case 20: return "Listar historias do projeto";
        case 21: return "Listar planos do projeto";
        case 22: return "Listar historias do plano de sprint";
        case 23: return "Listar historias da pessoa";
        case 24: return "Mover historia para plano de sprint";
        case 25: return "Alterar estado da historia";
        case 26: return "Listar projetos";
        default: return "Servico desconhecido";
    }
}

string ServicoAutorizacao::obterSecao(int servicoId) {
    switch (servicoId) {
        case 2: case 3: case 4:
            return "DADOS PESSOAIS";
        case 5: case 6: case 7: case 8: case 19: case 20: case 21: case 26:
            return "PROJETO";
        case 9: case 10: case 11: case 12: case 22: case 24:
            return "PLANO DE SPRINT";
        case 13: case 14: case 15: case 16: case 17: case 18: case 23: case 25:
            return "HISTORIA DE USUARIO";
        default:
            return "";
    }
}

vector<int> ServicoAutorizacao::ordenarPorSecao(const vector<int>& servicos) {
    static const string secoes[] = {
        "DADOS PESSOAIS",
        "PROJETO",
        "PLANO DE SPRINT",
        "HISTORIA DE USUARIO"
    };

    vector<int> ordenados;
    for (size_t s = 0; s < 4; ++s) {
        for (size_t i = 0; i < servicos.size(); ++i) {
            if (obterSecao(servicos[i]) == secoes[s]) {
                ordenados.push_back(servicos[i]);
            }
        }
    }
    return ordenados;
}
