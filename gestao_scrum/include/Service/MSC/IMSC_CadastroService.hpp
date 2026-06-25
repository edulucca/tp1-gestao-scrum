#pragma once

#include "Pessoa.hpp"

#include <string>
#include <vector>

using namespace std;

/**
 * @struct PessoaResumo
 * @ingroup msc
 * @brief Resumo de uma pessoa para consulta e listagem.
 */
struct PessoaResumo {
    string email; ///< Email da pessoa.
    string nome;  ///< Nome da pessoa.
    string papel; ///< Papel da pessoa no projeto.
};

/**
 * @struct ProjetoResumo
 * @ingroup msc
 * @brief Resumo de um projeto para consulta e listagem.
 */
struct ProjetoResumo {
    string codigo;      ///< Codigo identificador do projeto.
    string nome;        ///< Nome do projeto.
    string dataInicio;  ///< Data de inicio no formato DD/MM/AAAA.
    string dataTermino; ///< Data de termino no formato DD/MM/AAAA.
};

/**
 * @struct PlanoResumo
 * @ingroup msc
 * @brief Resumo de um plano de sprint para consulta e listagem.
 */
struct PlanoResumo {
    string codigo;    ///< Codigo identificador do plano.
    string objetivo;  ///< Objetivo do plano de sprint.
    int capacidade;   ///< Capacidade em dias.
};

/**
 * @class IMSC_CadastroService
 * @ingroup msc
 * @brief Interface do servico de cadastro de pessoas (MSC).
 *
 * Especifica operacoes de criacao, leitura, atualizacao, exclusao e listagem
 * de pessoas, alem da validacao de credenciais para autenticacao.
 */
class IMSC_CadastroService {
public:
    /** @brief Destrutor virtual padrao. */
    virtual ~IMSC_CadastroService() = default;

    /**
     * @brief Cria uma nova pessoa no armazenamento.
     * @param pessoa Entidade com dados validados.
     * @return true se criada com sucesso; false se o email ja existir.
     */
    virtual bool criarPessoa(Pessoa& pessoa) = 0;

    /**
     * @brief Le os dados resumidos de uma pessoa pelo email.
     * @param email Email da pessoa.
     * @param resumo Saida: dados resumidos da pessoa.
     * @return true se encontrada; false caso contrario.
     */
    virtual bool lerPessoa(const string& email, PessoaResumo& resumo) = 0;

    /**
     * @brief Atualiza nome e papel de uma pessoa existente.
     * @param email Email da pessoa.
     * @param nome Novo nome validado.
     * @param papel Novo papel validado.
     * @return true se atualizada com sucesso; false se nao encontrada.
     */
    virtual bool atualizarPessoa(const string& email, const string& nome, const string& papel) = 0;

    /**
     * @brief Exclui uma pessoa pelo email.
     * @param email Email da pessoa.
     * @return true se excluida com sucesso; false se nao encontrada.
     */
    virtual bool excluirPessoa(const string& email) = 0;

    /**
     * @brief Lista todas as pessoas cadastradas.
     * @return Vetor com resumos de todas as pessoas.
     */
    virtual vector<PessoaResumo> listarPessoas() = 0;

    /**
     * @brief Valida credenciais de acesso de uma pessoa.
     * @param email Email informado.
     * @param senha Senha informada.
     * @param nomeUsuario Saida: nome do usuario autenticado.
     * @param papelUsuario Saida: papel do usuario autenticado.
     * @return true se as credenciais forem validas; false caso contrario.
     */
    virtual bool validarCredenciais(
        const string& email,
        const string& senha,
        string& nomeUsuario,
        string& papelUsuario) = 0;
};
