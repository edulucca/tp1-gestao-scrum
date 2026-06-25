#pragma once

#include "IMSC_CadastroService.hpp"
#include "Pessoa.hpp"

#include <string>

using namespace std;

/**
 * @class CntrIU_MAC
 * @ingroup mac
 * @brief Controladora de apresentacao do modulo de cadastro (MAC).
 *
 * Responsavel por interagir com o usuario nas operacoes de pessoa, validar
 * dados de entrada com dominios e delegar as acoes ao IMSC_CadastroService.
 */
class CntrIU_MAC {
private:
    IMSC_CadastroService* cntrMSCCadastroService; ///< Servico de cadastro injetado.

public:
    /** @brief Constroi a controladora sem servico associado. */
    CntrIU_MAC();

    /**
     * @brief Injeta a implementacao do servico de cadastro.
     * @param cntrMSCCadastroService Ponteiro para IMSC_CadastroService.
     */
    void setCntrMSCCadastroService(IMSC_CadastroService* cntrMSCCadastroService);

    /**
     * @brief Executa um servico de cadastro de pessoa conforme o identificador.
     * @param servicoId Identificador do servico (1 a 4).
     * @param emailUsuario Email do usuario logado (usado nos servicos 2 e 3).
     * @return true se a operacao for concluida com sucesso; false caso contrario.
     */
    bool executarServico(int servicoId, const string& emailUsuario = "");
};
