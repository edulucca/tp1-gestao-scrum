#include "MSA_AuthServiceStub.hpp"
#include "IMSC_CadastroService.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

const int MSA_AuthServiceStub::TRIGGER_FALHA = 67890;
const int MSA_AuthServiceStub::TRIGGER_ERRO_SISTEMA = 78901;

MSA_AuthServiceStub::MSA_AuthServiceStub() : cadastroService(nullptr) {}

void MSA_AuthServiceStub::setCadastroService(IMSC_CadastroService* cadastroService) {
    this->cadastroService = cadastroService;
}

int MSA_AuthServiceStub::extrairGatilho(const string& email) const {
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

bool MSA_AuthServiceStub::autenticar(
    const string& email,
    const string& senha,
    string& nomeUsuario,
    string& papelUsuario) {
    cout << endl << "MSA_AuthServiceStub::autenticar" << endl;
    cout << "Email = " << email << endl;
    cout << "Senha = " << senha << endl;

    nomeUsuario.clear();
    papelUsuario.clear();

    switch (extrairGatilho(email)) {
        case TRIGGER_FALHA:
            return false;
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
        default:
            break;
    }

    if (cadastroService == nullptr) {
        return false;
    }

    return cadastroService->validarCredenciais(email, senha, nomeUsuario, papelUsuario);
}
