#pragma once
#include <string>

using namespace std;

/**
 * @class PlanoSprint
 * @brief Entidade que representa um plano de sprint.
 *
 * Agrega o Codigo (chave primaria), o Objetivo (Texto) e a Capacidade (Tempo,
 * em dias). Os valores sao acessados por metodos set/get que delegam a
 * validacao aos respectivos dominios.
 */
class PlanoSprint {
    private:
        class Impl;   ///< Implementacao oculta.
        Impl* impl;   ///< Ponteiro para a implementacao interna.

    public:
        /** @brief Constroi um plano de sprint vazio. */
        PlanoSprint();

        /** @brief Libera os recursos internos do plano de sprint. */
        ~PlanoSprint();

        /**
         * @brief Define o codigo identificador do plano de sprint.
         * @param codigo Codigo valido (ex.: "PS001").
         * @throw invalid_argument Se o codigo for invalido.
         */
        void setCodigo(const string&);

        /**
         * @brief Define o objetivo do plano de sprint.
         * @param objetivo Texto valido (ex.: "Entregar o cadastro de contas").
         * @throw invalid_argument Se o objetivo for invalido.
         */
        void setObjetivo(const string&);

        /**
         * @brief Define a capacidade do plano de sprint em dias.
         * @param capacidade Numero de dias valido (ex.: 15).
         * @throw invalid_argument Se estiver fora do intervalo 1 a 365.
         */
        void setCapacidade(int);

        /**
         * @brief Obtem o codigo do plano de sprint.
         * @return Codigo atual (ex.: retorna "PS001").
         */
        string getCodigo() const;

        /**
         * @brief Obtem o objetivo do plano de sprint.
         * @return Objetivo atual (ex.: retorna "Entregar o cadastro de contas").
         */
        string getObjetivo() const;

        /**
         * @brief Obtem a capacidade do plano de sprint em dias.
         * @return Numero de dias atual (ex.: retorna 15).
         */
        int getCapacidade() const;
};
