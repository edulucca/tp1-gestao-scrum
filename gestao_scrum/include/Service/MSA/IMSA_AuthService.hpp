#pragma once

#include <string>

using namespace std;

/**
 * @class IMSA_AuthService
 * @ingroup msa
 * @brief Interface do servico de autenticacao (MSA).
 *
 * Especifica a operacao de autenticacao de usuario por email e senha,
 * retornando nome e papel em caso de sucesso.
 */
class IMSA_AuthService {
public:
    /** @brief Destrutor virtual padrao. */
    virtual ~IMSA_AuthService() = default;

    /**
     * @brief Autentica um usuario pelas credenciais informadas.
     * @param email Email do usuario.
     * @param senha Senha do usuario.
     * @param nomeUsuario Saida: nome do usuario autenticado.
     * @param papelUsuario Saida: papel do usuario autenticado.
     * @return true se as credenciais forem validas; false caso contrario.
     */
    virtual bool autenticar(
        const string& email,
        const string& senha,
        string& nomeUsuario,
        string& papelUsuario) = 0;
};
