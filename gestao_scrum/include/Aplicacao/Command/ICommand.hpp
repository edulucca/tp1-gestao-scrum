#pragma once

/**
 * @class ICommand
 * @ingroup aplicacao
 * @brief Interface do padrao Command para encapsular acoes da apresentacao.
 *
 * Cada comando concreto delega a execucao a um servico via execute().
 */
class ICommand {
public:
    virtual ~ICommand() = default;

    /**
     * @brief Executa a acao encapsulada pelo comando.
     */
    virtual void execute() = 0;
};
