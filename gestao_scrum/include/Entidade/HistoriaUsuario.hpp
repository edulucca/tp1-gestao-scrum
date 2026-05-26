#pragma once
#include <string>

using namespace std;

/**
 * @class HistoriaUsuario
 * @brief Entidade que representa uma historia de usuario (user story).
 *
 * Agrega o Codigo (chave primaria), o Titulo e a descricao composta por Papel
 * (como...), Acao (eu quero...) e Valor (para...), alem da Estimativa (Tempo),
 * Prioridade e Estado. Ao ser criada, inicia no estado "A FAZER".
 */
class HistoriaUsuario {
    private:
        class Impl;   ///< Implementacao oculta.
        Impl* impl;   ///< Ponteiro para a implementacao interna.

    public:
        /** @brief Constroi uma historia de usuario com estado inicial "A FAZER". */
        HistoriaUsuario();

        /** @brief Libera os recursos internos da historia de usuario. */
        ~HistoriaUsuario();

        /**
         * @brief Define o codigo identificador da historia.
         * @param codigo Codigo valido (ex.: "HU001").
         * @throw invalid_argument Se o codigo for invalido.
         */
        void setCodigo(const string&);

        /**
         * @brief Define o titulo da historia.
         * @param titulo Texto valido (ex.: "Criar conta de usuario").
         * @throw invalid_argument Se o titulo for invalido.
         */
        void setTitulo(const string&);

        /**
         * @brief Define o papel da historia (parte "como...").
         * @param papel Texto valido (ex.: "Proprietario de Produto").
         * @throw invalid_argument Se o papel for invalido.
         */
        void setPapel(const string&);

        /**
         * @brief Define a acao da historia (parte "eu quero...").
         * @param acao Texto valido (ex.: "cadastrar uma conta").
         * @throw invalid_argument Se a acao for invalida.
         */
        void setAcao(const string&);

        /**
         * @brief Define o valor da historia (parte "para...").
         * @param valor Texto valido (ex.: "acessar os servicos").
         * @throw invalid_argument Se o valor for invalido.
         */
        void setValor(const string&);

        /**
         * @brief Define a estimativa da historia em dias.
         * @param estimativa Numero de dias valido (ex.: 5).
         * @throw invalid_argument Se estiver fora do intervalo 1 a 365.
         */
        void setEstimativa(int);

        /**
         * @brief Define a prioridade da historia.
         * @param prioridade Valor valido (ex.: "ALTA").
         * @throw invalid_argument Se a prioridade for invalida.
         */
        void setPrioridade(const string&);

        /**
         * @brief Define o estado da historia.
         * @param estado Valor valido (ex.: "FAZENDO").
         * @throw invalid_argument Se o estado for invalido.
         */
        void setEstado(const string&);

        /**
         * @brief Obtem o codigo da historia.
         * @return Codigo atual (ex.: retorna "HU001").
         */
        string getCodigo() const;

        /**
         * @brief Obtem o titulo da historia.
         * @return Titulo atual (ex.: retorna "Criar conta de usuario").
         */
        string getTitulo() const;

        /**
         * @brief Obtem o papel da historia.
         * @return Papel atual (ex.: retorna "Proprietario de Produto").
         */
        string getPapel() const;

        /**
         * @brief Obtem a acao da historia.
         * @return Acao atual (ex.: retorna "cadastrar uma conta").
         */
        string getAcao() const;

        /**
         * @brief Obtem o valor da historia.
         * @return Valor atual (ex.: retorna "acessar os servicos").
         */
        string getValor() const;

        /**
         * @brief Obtem a estimativa da historia em dias.
         * @return Numero de dias atual (ex.: retorna 5).
         */
        int getEstimativa() const;

        /**
         * @brief Obtem a prioridade da historia.
         * @return Prioridade atual (ex.: retorna "ALTA").
         */
        string getPrioridade() const;

        /**
         * @brief Obtem o estado da historia.
         * @return Estado atual (ex.: retorna "FAZENDO").
         */
        string getEstado() const;
};
