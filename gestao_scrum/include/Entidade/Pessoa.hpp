#pragma once
#include <string>

using namespace std;

/**
 * @class Pessoa
 * @brief Entidade que representa um usuario do sistema.
 *
 * Agrega os dominios Email (chave primaria), Nome, Senha e Papel. Os valores
 * sao acessados por metodos set/get que delegam a validacao aos respectivos
 * dominios.
 */
class Pessoa {
    private:
        class Impl;   ///< Implementacao oculta.
        Impl* impl;   ///< Ponteiro para a implementacao interna.

    public:
        /** @brief Constroi uma pessoa vazia. */
        Pessoa();

        /** @brief Libera os recursos internos da pessoa. */
        ~Pessoa();

        /**
         * @brief Define o email da pessoa (chave primaria).
         * @param email Email valido (ex.: "luis.serra@unb.br").
         * @throw invalid_argument Se o email for invalido ou ja estiver definido.
         */
        void setEmail(const string&);

        /**
         * @brief Define o nome da pessoa.
         * @param nome Nome valido (ex.: "Luis Serra").
         * @throw invalid_argument Se o nome for invalido.
         */
        void setNome(const string&);

        /**
         * @brief Define a senha da pessoa.
         * @param senha Senha valida (ex.: "a1B2c3").
         * @throw invalid_argument Se a senha for invalida.
         */
        void setSenha(const string&);

        /**
         * @brief Define o papel (role) da pessoa no projeto.
         * @param papel Papel valido (ex.: "MESTRE SCRUM").
         * @throw invalid_argument Se o papel for invalido.
         */
        void setPapel(const string&);

        /**
         * @brief Obtem o email da pessoa.
         * @return Email atual (ex.: retorna "luis.serra@unb.br").
         */
        string getEmail() const;

        /**
         * @brief Obtem o nome da pessoa.
         * @return Nome atual (ex.: retorna "Luis Serra").
         */
        string getNome() const;

        /**
         * @brief Obtem a senha da pessoa.
         * @return Senha atual (ex.: retorna "a1B2c3").
         */
        string getSenha() const;

        /**
         * @brief Obtem o papel da pessoa.
         * @return Papel atual (ex.: retorna "MESTRE SCRUM").
         */
        string getPapel() const;
};
