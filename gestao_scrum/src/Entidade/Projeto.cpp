#include "Projeto.hpp"
#include "Nome.hpp"
#include "Data.hpp"

using namespace std;

struct Projeto::Impl {
    Nome nome;
    Data dataInicio;
    Data dataTermino;
};

Projeto::Projeto() : impl(new Impl()) {}

Projeto::~Projeto(){
    delete impl;
}

void Projeto::setNome(const string& nome){
    impl->nome.setNome(nome);
}

void Projeto::setDataInicio(const string& data){
    impl->dataInicio.setData(data);
}


void Projeto::setDataTermino(const string& data){
    impl->dataTermino.setData(data);
}

string Projeto::getNome() const {
    return impl->nome.getNome();
}

string Projeto::getDataInicio() const {
    return impl->dataInicio.getData();
}

string Projeto::getDataTermino() const {
    return impl->dataTermino.getData();
}
