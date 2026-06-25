#pragma once

#include "IMSG_GestaoService.hpp"

#include <string>

using namespace std;

/**
 * @class CntrIU_MAG
 * @ingroup mag
 * @brief Controladora de apresentacao do modulo de gestao (MAG).
 *
 * Responsavel por interagir com o usuario nas operacoes de projetos, planos
 * de sprint e historias de usuario, validar entrada com dominios e delegar
 * as acoes ao IMSG_GestaoService.
 */
class CntrIU_MAG {
private:
    IMSG_GestaoService* cntrMSGGestaoService; ///< Servico de gestao injetado.

public:
    /** @brief Constroi a controladora sem servico associado. */
    CntrIU_MAG();

    /**
     * @brief Injeta a implementacao do servico de gestao.
     * @param cntrMSGGestaoService Ponteiro para IMSG_GestaoService.
     */
    void setCntrMSGGestaoService(IMSG_GestaoService* cntrMSGGestaoService);

    /**
     * @brief Executa um servico de gestao conforme o identificador.
     * @param servicoId Identificador do servico (5 a 26).
     * @param emailUsuario Email do usuario logado.
     * @return true se a operacao for concluida com sucesso; false caso contrario.
     */
    bool executarServico(int servicoId, const string& emailUsuario);
};
