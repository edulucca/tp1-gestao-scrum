#pragma once

#include "HistoriaUsuario.hpp"
#include "PlanoSprint.hpp"
#include "Projeto.hpp"
#include "IMSC_CadastroService.hpp"

#include <string>
#include <vector>

using namespace std;

/**
 * @class IMSG_GestaoService
 * @ingroup msg
 * @brief Interface do servico de gestao Scrum (MSG).
 *
 * Especifica operacoes de CRUD e consultas sobre projetos, planos de sprint
 * e historias de usuario, incluindo associacoes e alteracao de estado.
 */
class IMSG_GestaoService {
public:
    /** @brief Destrutor virtual padrao. */
    virtual ~IMSG_GestaoService() = default;

    /**
     * @brief Cria um novo projeto associado a um responsavel.
     * @param projeto Entidade com dados validados.
     * @param emailResponsavel Email do responsavel pelo projeto.
     * @return true se criado com sucesso; false caso contrario.
     */
    virtual bool criarProjeto(Projeto& projeto, const string& emailResponsavel) = 0;

    /**
     * @brief Le os dados resumidos de um projeto pelo codigo.
     * @param codigo Codigo do projeto.
     * @param resumo Saida: dados resumidos do projeto.
     * @return true se encontrado; false caso contrario.
     */
    virtual bool lerProjeto(const string& codigo, ProjetoResumo& resumo) = 0;

    /**
     * @brief Atualiza o nome de um projeto existente.
     * @param codigo Codigo do projeto.
     * @param nome Novo nome validado.
     * @return true se atualizado com sucesso; false caso contrario.
     */
    virtual bool atualizarProjeto(const string& codigo, const string& nome) = 0;

    /**
     * @brief Exclui um projeto pelo codigo.
     * @param codigo Codigo do projeto.
     * @return true se excluido com sucesso; false caso contrario.
     */
    virtual bool excluirProjeto(const string& codigo) = 0;

    /**
     * @brief Cria um plano de sprint vinculado a um projeto.
     * @param plano Entidade com dados validados.
     * @param codigoProjeto Codigo do projeto associado.
     * @return true se criado com sucesso; false caso contrario.
     */
    virtual bool criarPlanoSprint(PlanoSprint& plano, const string& codigoProjeto) = 0;

    /**
     * @brief Le os dados resumidos de um plano de sprint pelo codigo.
     * @param codigo Codigo do plano.
     * @param resumo Saida: dados resumidos do plano.
     * @return true se encontrado; false caso contrario.
     */
    virtual bool lerPlanoSprint(const string& codigo, PlanoResumo& resumo) = 0;

    /**
     * @brief Atualiza objetivo e capacidade de um plano de sprint.
     * @param codigo Codigo do plano.
     * @param objetivo Novo objetivo validado.
     * @param capacidade Nova capacidade em dias.
     * @return true se atualizado com sucesso; false caso contrario.
     */
    virtual bool atualizarPlanoSprint(const string& codigo, const string& objetivo, int capacidade) = 0;

    /**
     * @brief Exclui um plano de sprint pelo codigo.
     * @param codigo Codigo do plano.
     * @return true se excluido com sucesso; false caso contrario.
     */
    virtual bool excluirPlanoSprint(const string& codigo) = 0;

    /**
     * @brief Cria uma historia de usuario vinculada a um projeto.
     * @param historia Entidade com dados validados.
     * @param codigoProjeto Codigo do projeto associado.
     * @return true se criada com sucesso; false caso contrario.
     */
    virtual bool criarHistoria(HistoriaUsuario& historia, const string& codigoProjeto) = 0;

    /**
     * @brief Le uma historia de usuario pelo codigo.
     * @param codigo Codigo da historia.
     * @return Ponteiro para a historia ou nullptr se nao encontrada.
     */
    virtual HistoriaUsuario* lerHistoria(const string& codigo) = 0;

    /**
     * @brief Atualiza os dados de uma historia de usuario existente.
     * @param historia Entidade com dados atualizados.
     * @return true se atualizada com sucesso; false caso contrario.
     */
    virtual bool atualizarHistoria(HistoriaUsuario& historia) = 0;

    /**
     * @brief Exclui uma historia de usuario pelo codigo.
     * @param codigo Codigo da historia.
     * @return true se excluida com sucesso; false caso contrario.
     */
    virtual bool excluirHistoria(const string& codigo) = 0;

    /**
     * @brief Associa uma historia de usuario a uma pessoa pelo email.
     * @param codigoHistoria Codigo da historia.
     * @param email Email da pessoa.
     * @return true se associada com sucesso; false caso contrario.
     */
    virtual bool associarHistoriaPessoa(const string& codigoHistoria, const string& email) = 0;

    /**
     * @brief Remove a associacao entre uma historia e uma pessoa.
     * @param codigoHistoria Codigo da historia.
     * @param email Email da pessoa.
     * @return true se removida com sucesso; false caso contrario.
     */
    virtual bool removerAssociacaoHistoriaPessoa(const string& codigoHistoria, const string& email) = 0;

    /**
     * @brief Lista todos os projetos cadastrados.
     * @return Vetor com resumos de todos os projetos.
     */
    virtual vector<ProjetoResumo> listarProjetos() = 0;

    /**
     * @brief Lista projetos associados a uma pessoa.
     * @param email Email da pessoa.
     * @return Vetor com resumos dos projetos da pessoa.
     */
    virtual vector<ProjetoResumo> listarProjetosPorPessoa(const string& email) = 0;

    /**
     * @brief Lista historias de um projeto.
     * @param codigoProjeto Codigo do projeto.
     * @return Vetor de ponteiros para as historias do projeto.
     */
    virtual vector<HistoriaUsuario*> listarHistoriasPorProjeto(const string& codigoProjeto) = 0;

    /**
     * @brief Lista planos de sprint de um projeto.
     * @param codigoProjeto Codigo do projeto.
     * @return Vetor com resumos dos planos do projeto.
     */
    virtual vector<PlanoResumo> listarPlanosPorProjeto(const string& codigoProjeto) = 0;

    /**
     * @brief Lista historias alocadas em um plano de sprint.
     * @param codigoPlano Codigo do plano.
     * @return Vetor de ponteiros para as historias do plano.
     */
    virtual vector<HistoriaUsuario*> listarHistoriasPorPlano(const string& codigoPlano) = 0;

    /**
     * @brief Lista historias associadas a uma pessoa.
     * @param email Email da pessoa.
     * @return Vetor de ponteiros para as historias da pessoa.
     */
    virtual vector<HistoriaUsuario*> listarHistoriasPorPessoa(const string& email) = 0;

    /**
     * @brief Move uma historia para um plano de sprint.
     * @param codigoHistoria Codigo da historia.
     * @param codigoPlano Codigo do plano de destino.
     * @return true se movida com sucesso; false caso contrario.
     */
    virtual bool moverHistoriaParaPlano(const string& codigoHistoria, const string& codigoPlano) = 0;

    /**
     * @brief Altera o estado de uma historia de usuario.
     * @param codigoHistoria Codigo da historia.
     * @param estado Novo estado validado.
     * @return true se alterado com sucesso; false caso contrario.
     */
    virtual bool alterarEstadoHistoria(const string& codigoHistoria, const string& estado) = 0;
};
