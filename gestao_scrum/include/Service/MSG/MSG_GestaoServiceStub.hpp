#pragma once

#include "IMSG_GestaoService.hpp"

#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/**
 * @class MSG_GestaoServiceStub
 * @ingroup msg
 * @brief Implementacao stub do servico de gestao Scrum (MSG).
 *
 * Armazena projetos, planos de sprint e historias de usuario em memoria e
 * implementa todas as operacoes de gestao definidas em IMSG_GestaoService.
 */
class MSG_GestaoServiceStub : public IMSG_GestaoService {
private:
    static const int TRIGGER_FALHA;        ///< Gatilho: retorna falha na operacao.
    static const int TRIGGER_ERRO_SISTEMA; ///< Gatilho: lanca erro de sistema.

    struct HistoriaRegistro {
        HistoriaUsuario* historia;
        string codigoProjeto;
        string codigoPlano;
        vector<string> emailsPessoas;
    };

    struct ProjetoRegistro {
        string codigo;
        string nome;
        string dataInicio;
        string dataTermino;
    };

    struct PlanoRegistro {
        string codigo;
        string codigoProjeto;
        string objetivo;
        int capacidade;
    };

    list<HistoriaRegistro> historias;           ///< Historias armazenadas em memoria.
    list<ProjetoRegistro> projetos;             ///< Projetos armazenados em memoria.
    list<PlanoRegistro> planos;                 ///< Planos armazenados em memoria.
    map<string, vector<string>> projetosPorPessoa; ///< Associacao pessoa-projeto.

    int extrairGatilhoCodigo(const string& codigo) const;
    void verificarGatilho(const string& codigo) const;
    bool gatilhoFalha(const string& codigo) const;
    HistoriaRegistro* buscarHistoria(const string& codigo);
    void popularDadosIniciais();
    void liberarHistorias();

public:
    /** @brief Constroi o stub populando dados iniciais de teste. */
    MSG_GestaoServiceStub();

    /** @brief Libera historias alocadas dinamicamente. */
    ~MSG_GestaoServiceStub();

    /** @brief Cria projeto e associa ao responsavel. */
    bool criarProjeto(Projeto& projeto, const string& emailResponsavel) override;

    /** @brief Le resumo de projeto pelo codigo. */
    bool lerProjeto(const string& codigo, ProjetoResumo& resumo) override;

    /** @brief Atualiza nome de projeto existente. */
    bool atualizarProjeto(const string& codigo, const string& nome) override;

    /** @brief Exclui projeto pelo codigo. */
    bool excluirProjeto(const string& codigo) override;

    /** @brief Cria plano de sprint vinculado a projeto. */
    bool criarPlanoSprint(PlanoSprint& plano, const string& codigoProjeto) override;

    /** @brief Le resumo de plano pelo codigo. */
    bool lerPlanoSprint(const string& codigo, PlanoResumo& resumo) override;

    /** @brief Atualiza objetivo e capacidade de plano existente. */
    bool atualizarPlanoSprint(const string& codigo, const string& objetivo, int capacidade) override;

    /** @brief Exclui plano pelo codigo. */
    bool excluirPlanoSprint(const string& codigo) override;

    /** @brief Cria historia vinculada a projeto. */
    bool criarHistoria(HistoriaUsuario& historia, const string& codigoProjeto) override;

    /** @brief Le historia pelo codigo. */
    HistoriaUsuario* lerHistoria(const string& codigo) override;

    /** @brief Atualiza dados de historia existente. */
    bool atualizarHistoria(HistoriaUsuario& historia) override;

    /** @brief Exclui historia pelo codigo. */
    bool excluirHistoria(const string& codigo) override;

    /** @brief Associa historia a pessoa pelo email. */
    bool associarHistoriaPessoa(const string& codigoHistoria, const string& email) override;

    /** @brief Remove associacao entre historia e pessoa. */
    bool removerAssociacaoHistoriaPessoa(const string& codigoHistoria, const string& email) override;

    /** @brief Lista todos os projetos. */
    vector<ProjetoResumo> listarProjetos() override;

    /** @brief Lista projetos de uma pessoa. */
    vector<ProjetoResumo> listarProjetosPorPessoa(const string& email) override;

    /** @brief Lista historias de um projeto. */
    vector<HistoriaUsuario*> listarHistoriasPorProjeto(const string& codigoProjeto) override;

    /** @brief Lista planos de um projeto. */
    vector<PlanoResumo> listarPlanosPorProjeto(const string& codigoProjeto) override;

    /** @brief Lista historias de um plano. */
    vector<HistoriaUsuario*> listarHistoriasPorPlano(const string& codigoPlano) override;

    /** @brief Lista historias de uma pessoa. */
    vector<HistoriaUsuario*> listarHistoriasPorPessoa(const string& email) override;

    /** @brief Move historia para plano de sprint. */
    bool moverHistoriaParaPlano(const string& codigoHistoria, const string& codigoPlano) override;

    /** @brief Altera estado de historia de usuario. */
    bool alterarEstadoHistoria(const string& codigoHistoria, const string& estado) override;
};
