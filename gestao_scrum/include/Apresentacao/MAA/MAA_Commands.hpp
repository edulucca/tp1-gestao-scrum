#pragma once

#include "ICommand.hpp"
#include "IMSA_AuthService.hpp"

#include <string>

using namespace std;

/**
 * @class LoginCommand
 * @ingroup maa
 * @brief Comando concreto que delega autenticacao ao IMSA_AuthService.
 */
class LoginCommand : public ICommand {
private:
    IMSA_AuthService* authService; ///< Servico receptor da autenticacao.
    string email;                ///< Email informado pelo usuario.
    string senha;                ///< Senha informada pelo usuario.
    bool* resultado;             ///< Saida: resultado da autenticacao.
    string* nomeUsuario;         ///< Saida: nome do usuario autenticado.
    string* papelUsuario;        ///< Saida: papel do usuario autenticado.

public:
    /**
     * @brief Constroi o comando de login.
     * @param authService Servico de autenticacao.
     * @param email Email validado do usuario.
     * @param senha Senha validada do usuario.
     * @param resultado Ponteiro para armazenar o resultado.
     * @param nomeUsuario Ponteiro para armazenar o nome retornado.
     * @param papelUsuario Ponteiro para armazenar o papel retornado.
     */
    LoginCommand(
        IMSA_AuthService* authService,
        const string& email,
        const string& senha,
        bool* resultado,
        string* nomeUsuario,
        string* papelUsuario);

    /** @brief Executa a autenticacao via servico injetado. */
    void execute() override;
};

/**
 * @class LogoutCommand
 * @ingroup maa
 * @brief Comando concreto que exibe confirmacao de logout ao usuario.
 */
class LogoutCommand : public ICommand {
public:
    /** @brief Exibe mensagem de logout realizado. */
    void execute() override;
};
