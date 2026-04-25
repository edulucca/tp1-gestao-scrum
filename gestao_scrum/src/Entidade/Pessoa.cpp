#include "../../include/Entidade/Pessoa.hpp"
#include "../../include/Dominio/Email.hpp"
#include "../../include/Dominio/Nome.hpp"
#include "../../include/Dominio/Senha.hpp"
#include "../../include/Dominio/Papel.hpp"

using namespace std;

struct Pessoa::Impl {
    Email email;
    Nome  nome;
    Senha senha;
    Papel papel;
};

Pessoa::Pessoa() : impl(new Impl()) {}

Pessoa::~Pessoa() {
    delete impl;
}

void Pessoa::setEmail(const string& email) {
    if (!impl->email.getEmail().empty()) {
        throw invalid_argument("Email ja definido para esta pessoa.");
    }
    impl->email.setEmail(email);
}

void Pessoa::setNome(const string& nome) {
    impl->nome.setNome(nome);
}

void Pessoa::setSenha(const string& senha) {
    impl->senha.setSenha(senha);
}

void Pessoa::setPapel(const string& papel) {
    impl->papel.setPapel(papel);
}

string Pessoa::getEmail() const {
    return impl->email.getEmail();
}

string Pessoa::getNome() const {
    return impl->nome.getNome();
}

string Pessoa::getSenha() const {
    return impl->senha.getSenha();
}

string Pessoa::getPapel() const {
    return impl->papel.getPapel();
}
