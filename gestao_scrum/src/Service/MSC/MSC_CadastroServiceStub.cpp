#include "MSC_CadastroServiceStub.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

const int MSC_CadastroServiceStub::TRIGGER_FALHA = 67890;
const int MSC_CadastroServiceStub::TRIGGER_ERRO_SISTEMA = 78901;
const string MSC_CadastroServiceStub::EMAIL_PADRAO = "luis.serra@unb.br";
const string MSC_CadastroServiceStub::SENHA_PADRAO = "a1B2c3";

int MSC_CadastroServiceStub::extrairGatilho(const string& email) const {
    string parteLocal = email;
    const size_t pos = email.find('@');
    if (pos != string::npos) {
        parteLocal = email.substr(0, pos);
    }
    try {
        return stoi(parteLocal);
    } catch (...) {
        return -1;
    }
}

bool MSC_CadastroServiceStub::emailExiste(const string& email) const {
    for (list<PessoaCadastrada>::const_iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (it->email == email) {
            return true;
        }
    }
    return false;
}

void MSC_CadastroServiceStub::popularUsuarioPadrao() {
    PessoaCadastrada usuarioPadrao;
    usuarioPadrao.email = EMAIL_PADRAO;
    usuarioPadrao.nome = "Luis Serra";
    usuarioPadrao.senha = SENHA_PADRAO;
    usuarioPadrao.papel = "MESTRE SCRUM";
    pessoas.push_back(usuarioPadrao);
}

MSC_CadastroServiceStub::MSC_CadastroServiceStub() {
    popularUsuarioPadrao();
}

bool MSC_CadastroServiceStub::criarPessoa(Pessoa& pessoa) {
    cout << endl << "MSC_CadastroServiceStub::criarPessoa" << endl;
    switch (extrairGatilho(pessoa.getEmail())) {
        case TRIGGER_FALHA: return false;
        case TRIGGER_ERRO_SISTEMA: throw runtime_error("Erro de sistema");
        default: break;
    }
    if (emailExiste(pessoa.getEmail())) {
        return false;
    }
    PessoaCadastrada cadastro;
    cadastro.email = pessoa.getEmail();
    cadastro.nome = pessoa.getNome();
    cadastro.senha = pessoa.getSenha();
    cadastro.papel = pessoa.getPapel();
    pessoas.push_back(cadastro);
    return true;
}

bool MSC_CadastroServiceStub::lerPessoa(const string& email, PessoaResumo& resumo) {
    cout << endl << "MSC_CadastroServiceStub::lerPessoa" << endl;
    for (list<PessoaCadastrada>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (it->email == email) {
            resumo.email = it->email;
            resumo.nome = it->nome;
            resumo.papel = it->papel;
            return true;
        }
    }
    return false;
}

bool MSC_CadastroServiceStub::atualizarPessoa(const string& email, const string& nome, const string& papel) {
    cout << endl << "MSC_CadastroServiceStub::atualizarPessoa" << endl;
    for (list<PessoaCadastrada>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (it->email == email) {
            it->nome = nome;
            it->papel = papel;
            return true;
        }
    }
    return false;
}

bool MSC_CadastroServiceStub::excluirPessoa(const string& email) {
    cout << endl << "MSC_CadastroServiceStub::excluirPessoa" << endl;
    for (list<PessoaCadastrada>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (it->email == email) {
            pessoas.erase(it);
            return true;
        }
    }
    return false;
}

vector<PessoaResumo> MSC_CadastroServiceStub::listarPessoas() {
    cout << endl << "MSC_CadastroServiceStub::listarPessoas" << endl;
    vector<PessoaResumo> resultado;
    for (list<PessoaCadastrada>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        PessoaResumo resumo;
        resumo.email = it->email;
        resumo.nome = it->nome;
        resumo.papel = it->papel;
        resultado.push_back(resumo);
    }
    return resultado;
}

bool MSC_CadastroServiceStub::validarCredenciais(
    const string& email,
    const string& senha,
    string& nomeUsuario,
    string& papelUsuario) {
    for (list<PessoaCadastrada>::iterator it = pessoas.begin(); it != pessoas.end(); ++it) {
        if (it->email == email && it->senha == senha) {
            nomeUsuario = it->nome;
            papelUsuario = it->papel;
            return true;
        }
    }
    nomeUsuario.clear();
    papelUsuario.clear();
    return false;
}
