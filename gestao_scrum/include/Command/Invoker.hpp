#pragma once

#include "ICommand.hpp"
#include <memory>
#include <vector>

/**
 * @class Invoker
 * @ingroup command
 * @brief Invocador que executa comandos ICommand em sequencia.
 */
class Invoker {
private:
    std::vector<std::shared_ptr<ICommand>> queue;

public:
    /**
     * @brief Adiciona um comando a fila de execucao.
     * @param cmd Comando a enfileirar.
     */
    void addCommand(const std::shared_ptr<ICommand>& cmd);

    /**
     * @brief Executa todos os comandos enfileirados e esvazia a fila.
     */
    void runAll();
};
