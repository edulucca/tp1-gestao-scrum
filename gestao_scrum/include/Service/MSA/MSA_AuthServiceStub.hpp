#pragma once

#include "IMSA_AuthService.hpp"

class IMSC_CadastroService;

#include <stdexcept>
#include <string>

using namespace std;

/**
 * @class MSA_AuthServiceStub
 * @ingroup msa
 * @brief Implementacao stub do servico de autenticacao (MSA).
 *
 * Delega a validacao de credenciais ao IMSC_CadastroService e suporta
 * gatilhos de teste embutidos no email para simular falha e erro de sistema.
 */
class MSA_AuthServiceStub : public IMSA_AuthService {
private:
    static const int TRIGGER_FALHA;        ///< Gatilho: retorna falha de autenticacao.
    static const int TRIGGER_ERRO_SISTEMA; ///< Gatilho: lanca erro de sistema.

    IMSC_CadastroService* cadastroService; ///< Servico de cadastro para validar credenciais.

    int extrairGatilho(const string& email) const;

public:
    /** @brief Constroi o stub sem servico de cadastro associado. */
    MSA_AuthServiceStub();

    /**
     * @brief Injeta o servico de cadastro usado na validacao de credenciais.
     * @param cadastroService Ponteiro para IMSC_CadastroService.
     */
    void setCadastroService(IMSC_CadastroService* cadastroService);

    /**
     * @brief Autentica usuario delegando ao servico de cadastro.
     * @param email Email do usuario.
     * @param senha Senha do usuario.
     * @param nomeUsuario Saida: nome do usuario autenticado.
     * @param papelUsuario Saida: papel do usuario autenticado.
     * @return true se autenticado com sucesso; false caso contrario.
     * @throw runtime_error Se o gatilho de erro de sistema for acionado.
     */
    bool autenticar(
        const string& email,
        const string& senha,
        string& nomeUsuario,
        string& papelUsuario) override;
};
