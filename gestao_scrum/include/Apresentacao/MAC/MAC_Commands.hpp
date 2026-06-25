#pragma once

#include "ICommand.hpp"
#include "IMSC_CadastroService.hpp"
#include "Pessoa.hpp"

#include <vector>

using namespace std;

/**
 * @class CriarPessoaCommand
 * @ingroup mac
 * @brief Comando concreto que delega criacao de pessoa ao IMSC_CadastroService.
 */
class CriarPessoaCommand : public ICommand {
private:
    IMSC_CadastroService* cadastroService; ///< Servico receptor do cadastro.
    Pessoa* pessoa;                       ///< Pessoa a ser criada.
    bool* resultado;                      ///< Saida: resultado da operacao.

public:
    /**
     * @brief Constroi o comando de criacao de pessoa.
     * @param cadastroService Servico de cadastro.
     * @param pessoa Pessoa preenchida com dados validados.
     * @param resultado Ponteiro para armazenar o resultado.
     */
    CriarPessoaCommand(IMSC_CadastroService* cadastroService, Pessoa* pessoa, bool* resultado);

    /** @brief Executa a criacao de pessoa via servico injetado. */
    void execute() override;
};

/**
 * @class ListarPessoasCommand
 * @ingroup mac
 * @brief Comando concreto que delega listagem de pessoas ao IMSC_CadastroService.
 */
class ListarPessoasCommand : public ICommand {
private:
    IMSC_CadastroService* cadastroService; ///< Servico receptor do cadastro.
    vector<PessoaResumo>* pessoas;         ///< Saida: lista de pessoas retornada.

public:
    /**
     * @brief Constroi o comando de listagem de pessoas.
     * @param cadastroService Servico de cadastro.
     * @param pessoas Ponteiro para armazenar a lista retornada.
     */
    ListarPessoasCommand(IMSC_CadastroService* cadastroService, vector<PessoaResumo>* pessoas);

    /** @brief Executa a listagem de pessoas via servico injetado. */
    void execute() override;
};
