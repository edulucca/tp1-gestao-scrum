#pragma once

#include "IMSA_AuthService.hpp"

#include <string>

using namespace std;

/**
 * @class CntrIU_MAA
 * @ingroup maa
 * @brief Controladora de apresentacao do modulo de autenticacao (MAA).
 *
 * Responsavel por interagir com o usuario no login e logout, validar dados
 * de entrada com dominios e delegar a autenticacao ao IMSA_AuthService via
 * comandos do padrao Command.
 */
class CntrIU_MAA {
private:
    IMSA_AuthService* cntrMSAAuthService; ///< Servico de autenticacao injetado.

public:
    /** @brief Constroi a controladora sem servico associado. */
    CntrIU_MAA();

    /**
     * @brief Injeta a implementacao do servico de autenticacao.
     * @param cntrMSAAuthService Ponteiro para IMSA_AuthService.
     */
    void setCntrMSAAuthService(IMSA_AuthService* cntrMSAAuthService);

    /**
     * @brief Solicita email e senha, valida a entrada e executa o login.
     * @param nomeUsuario Saida: nome do usuario autenticado.
     * @param papelUsuario Saida: papel do usuario autenticado.
     * @param emailUsuario Saida: email validado informado pelo usuario.
     * @return true se a autenticacao for bem-sucedida; false caso contrario.
     */
    bool login(string& nomeUsuario, string& papelUsuario, string& emailUsuario);

    /**
     * @brief Executa o fluxo de logout do usuario.
     */
    void logout();
};
