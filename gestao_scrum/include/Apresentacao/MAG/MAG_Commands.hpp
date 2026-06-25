#pragma once

#include "ICommand.hpp"
#include "IMSG_GestaoService.hpp"
#include "HistoriaUsuario.hpp"

#include <string>
#include <vector>

using namespace std;

/**
 * @class ListarHistoriasCommand
 * @ingroup mag
 * @brief Comando concreto que delega listagem de historias ao IMSG_GestaoService.
 */
class ListarHistoriasCommand : public ICommand {
private:
    IMSG_GestaoService* gestaoService;       ///< Servico receptor de gestao.
    string codigoProjeto;                    ///< Codigo do projeto filtrado.
    vector<HistoriaUsuario*>* historias;   ///< Saida: historias retornadas.

public:
    /**
     * @brief Constroi o comando de listagem de historias por projeto.
     * @param gestaoService Servico de gestao.
     * @param codigoProjeto Codigo do projeto.
     * @param historias Ponteiro para armazenar as historias retornadas.
     */
    ListarHistoriasCommand(
        IMSG_GestaoService* gestaoService,
        const string& codigoProjeto,
        vector<HistoriaUsuario*>* historias);

    /** @brief Executa a listagem de historias via servico injetado. */
    void execute() override;
};

/**
 * @class AtualizarHistoriaCommand
 * @ingroup mag
 * @brief Comando concreto que delega alteracao de estado de historia ao IMSG_GestaoService.
 */
class AtualizarHistoriaCommand : public ICommand {
private:
    IMSG_GestaoService* gestaoService; ///< Servico receptor de gestao.
    string codigoHistoria;             ///< Codigo da historia a alterar.
    string estado;                     ///< Novo estado validado.
    bool* resultado;                   ///< Saida: resultado da operacao.

public:
    /**
     * @brief Constroi o comando de atualizacao de estado de historia.
     * @param gestaoService Servico de gestao.
     * @param codigoHistoria Codigo da historia.
     * @param estado Novo estado da historia.
     * @param resultado Ponteiro para armazenar o resultado.
     */
    AtualizarHistoriaCommand(
        IMSG_GestaoService* gestaoService,
        const string& codigoHistoria,
        const string& estado,
        bool* resultado);

    /** @brief Executa a alteracao de estado via servico injetado. */
    void execute() override;
};
