#pragma once

#include <string>
#include <vector>

using namespace std;

/**
 * @class ServicoAutorizacao
 * @ingroup autorizacao
 * @brief Verifica se um papel pode executar um servico.
 *
 * Centraliza as regras de autorizacao por papel (DESENVOLVEDOR, MESTRE SCRUM,
 * PROPRIETARIO DE PRODUTO) e fornece dados dos servicos para a interface.
 */
class ServicoAutorizacao {
public:
    static const int TOTAL_SERVICOS = 26; ///< Quantidade total de servicos do sistema.

    /**
     * @brief Verifica se o papel informado pode executar o servico.
     * @param servicoId Identificador do servico.
     * @param papel Papel do usuario logado.
     * @return true se autorizado; false caso contrario.
     */
    static bool podeExecutar(int servicoId, const string& papel);

    /**
     * @brief Obtem a descricao textual de um servico.
     * @param servicoId Identificador do servico.
     * @return Descricao do servico ou string vazia se invalido.
     */
    static string obterDescricao(int servicoId);

    /**
     * @brief Obtem a secao do menu a que o servico pertence.
     * @param servicoId Identificador do servico.
     * @return Nome da secao ou string vazia se invalido.
     */
    static string obterSecao(int servicoId);

    /**
     * @brief Ordena servicos pela secao do menu.
     * @param servicos Lista de identificadores de servicos.
     * @return Lista ordenada por secao.
     */
    static vector<int> ordenarPorSecao(const vector<int>& servicos);
};
