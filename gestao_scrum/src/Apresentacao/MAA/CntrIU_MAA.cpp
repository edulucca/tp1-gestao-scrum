#include "CntrIU_MAA.hpp"
#include "MAA_Commands.hpp"
#include "Email.hpp"
#include "Senha.hpp"
#include "EntradaUsuario.hpp"
#include "Invoker.hpp"

#include <iostream>
#include <memory>

using namespace std;

CntrIU_MAA::CntrIU_MAA() : cntrMSAAuthService(nullptr) {}

void CntrIU_MAA::setCntrMSAAuthService(IMSA_AuthService* cntrMSAAuthService) {
    this->cntrMSAAuthService = cntrMSAAuthService;
}

bool CntrIU_MAA::login(string& nomeUsuario, string& papelUsuario, string& emailUsuario) {
    string entradaEmail;
    string entradaSenha;
    Email email;

    nomeUsuario.clear();
    papelUsuario.clear();
    emailUsuario.clear();

    while (true) {
        cout << endl << "Autenticacao de usuario." << endl << endl;
        try {
            cout << "Digite o email: ";
            cin >> entradaEmail;
            email.setEmail(entradaEmail);
            emailUsuario = email.getEmail();
            break;
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }

    while (true) {
        cout << "  Padrao de senha: 6 caracteres alternando letra e digito (ex: a1B2c3)" << endl;
        string entrada = EntradaUsuario::lerPalavra("Digite a senha", false);
        try {
            Senha senhaDom;
            senhaDom.setSenha(entrada);
            entradaSenha = senhaDom.getSenha();
            break;
        } catch (const invalid_argument& e) {
            cout << endl << e.what() << endl;
        }
    }

    bool resultado = false;
    Invoker invoker;
    invoker.addCommand(make_shared<LoginCommand>(
        cntrMSAAuthService,
        email.getEmail(),
        entradaSenha,
        &resultado,
        &nomeUsuario,
        &papelUsuario));
    invoker.runAll();

    return resultado;
}

void CntrIU_MAA::logout() {
    Invoker invoker;
    invoker.addCommand(make_shared<LogoutCommand>());
    invoker.runAll();
}
