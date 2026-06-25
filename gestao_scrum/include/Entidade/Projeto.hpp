#pragma once
#include <string>

using namespace std;

/**
 * @class Projeto
 * @ingroup entidade
 * @brief Entidade que representa um projeto gerido pelo processo Scrum.
 *
 * Agrega os dominios Codigo (chave primaria), Nome e duas Datas (inicio e
 * termino). Os valores sao acessados por metodos set/get que delegam a
 * validacao aos respectivos dominios.
 */
class Projeto {
    private:
        class Impl;   ///< Implementacao oculta.
        Impl* impl;   ///< Ponteiro para a implementacao interna.

    public:
        /** @brief Constroi um projeto vazio. */
        Projeto();

        /** @brief Libera os recursos internos do projeto. */
        ~Projeto();

        /**
         * @brief Define o nome do projeto.
         * @param nome Nome valido (ex.: "Scrum Tool").
         * @throw invalid_argument Se o nome for invalido.
         */
        void setNome(const string&);

        /**
         * @brief Define a data de inicio do projeto.
         * @param data Data valida "DD/MM/AAAA" (ex.: "01/03/2025").
         * @throw invalid_argument Se a data for invalida.
         */
        void setDataInicio(const string&);

        /**
         * @brief Define a data de termino do projeto.
         * @param data Data valida "DD/MM/AAAA" (ex.: "30/06/2025").
         * @throw invalid_argument Se a data for invalida.
         */
        void setDataTermino(const string&);

        /**
         * @brief Define o codigo identificador do projeto.
         * @param codigo Codigo valido (ex.: "PR001").
         * @throw invalid_argument Se o codigo for invalido.
         */
        void setCodigo(const string&);

        /**
         * @brief Obtem o nome do projeto.
         * @return Nome atual (ex.: retorna "Scrum Tool").
         */
        string getNome() const;

        /**
         * @brief Obtem a data de inicio do projeto.
         * @return Data de inicio (ex.: retorna "01/03/2025").
         */
        string getDataInicio() const;

        /**
         * @brief Obtem a data de termino do projeto.
         * @return Data de termino (ex.: retorna "30/06/2025").
         */
        string getDataTermino() const;

        /**
         * @brief Obtem o codigo do projeto.
         * @return Codigo atual (ex.: retorna "PR001").
         */
        string getCodigo() const;
};
