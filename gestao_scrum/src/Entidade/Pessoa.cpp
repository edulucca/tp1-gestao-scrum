/**
 * @file Pessoa.cpp
 * @brief Implementacao da entidade Pessoa de forma encapsulada.
 */
#include "../../include/Entidade/Pessoa.hpp"
#include "../../include/Dominio/Email.hpp"
#include "../../include/Dominio/Nome.hpp"
#include "../../include/Dominio/Senha.hpp"
#include "../../include/Dominio/Papel.hpp"

using namespace std;

/** @brief Estrutura interna que agrega os dominios da pessoa. */
struct Pessoa::Impl {
    Email email;    ///< Email (chave primaria).
    Nome  nome;     ///< Nome da pessoa.
    Senha senha;    ///< Senha de acesso.
    Papel papel;    ///< Papel no projeto.
};

/** @brief Constroi a pessoa alocando a implementacao interna. */
Pessoa::Pessoa() : impl(new Impl()) {}

/** @brief Libera a memoria da implementacao interna. */
Pessoa::~Pessoa() {
    delete impl;
}

/**
 * @brief Define o email da pessoa (nao pode ser redefinido).
 * @throw invalid_argument Se ja estiver definido ou for invalido.
 */
void Pessoa::setEmail(const string& email) {
    if (!impl->email.getEmail().empty()) {
        throw invalid_argument("Email ja definido para esta pessoa.");
    }
    impl->email.setEmail(email);
}

/**
 * @brief Define o nome da pessoa.
 * @throw invalid_argument Se o nome for invalido.
 */
void Pessoa::setNome(const string& nome) {
    impl->nome.setNome(nome);
}

/**
 * @brief Define a senha da pessoa.
 * @throw invalid_argument Se a senha for invalida.
 */
void Pessoa::setSenha(const string& senha) {
    impl->senha.setSenha(senha);
}

/**
 * @brief Define o papel da pessoa.
 * @throw invalid_argument Se o papel for invalido.
 */
void Pessoa::setPapel(const string& papel) {
    impl->papel.setPapel(papel);
}

/**
 * @brief Obtem o email da pessoa.
 * @return Email atual (ex.: retorna "luis.serra@unb.br").
 */
string Pessoa::getEmail() const {
    return impl->email.getEmail();
}

/**
 * @brief Obtem o nome da pessoa.
 * @return Nome atual (ex.: retorna "Luis Serra").
 */
string Pessoa::getNome() const {
    return impl->nome.getNome();
}

/**
 * @brief Obtem a senha da pessoa.
 * @return Senha atual (ex.: retorna "a1B2c3").
 */
string Pessoa::getSenha() const {
    return impl->senha.getSenha();
}

/**
 * @brief Obtem o papel da pessoa.
 * @return Papel atual (ex.: retorna "MESTRE SCRUM").
 */
string Pessoa::getPapel() const {
    return impl->papel.getPapel();
}
