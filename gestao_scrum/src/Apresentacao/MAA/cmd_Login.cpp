#include "MAA_Commands.hpp"

#include <iostream>

using namespace std;

LoginCommand::LoginCommand(
    IMSA_AuthService* authService,
    const string& email,
    const string& senha,
    bool* resultado,
    string* nomeUsuario,
    string* papelUsuario)
    : authService(authService),
      email(email),
      senha(senha),
      resultado(resultado),
      nomeUsuario(nomeUsuario),
      papelUsuario(papelUsuario) {}

void LoginCommand::execute() {
    if (authService != nullptr && resultado != nullptr && nomeUsuario != nullptr && papelUsuario != nullptr) {
        *resultado = authService->autenticar(email, senha, *nomeUsuario, *papelUsuario);
    }
}

void LogoutCommand::execute() {
    cout << endl << "Logout realizado com sucesso." << endl;
}
