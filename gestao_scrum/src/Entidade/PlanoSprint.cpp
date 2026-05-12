#include "PlanoSprint.hpp"

using namespace std;

// implementação construtor e destrutor

PlanoSprint::PlanoSprint(){
    // vazio proposital
}

PlanoSprint::~PlanoSprint(){
    // vazio proposital
}

// implementação setters

void PlanoSprint::setCodigo(const string& codigo){
    this->codigo.setCodigo(codigo);
}

void PlanoSprint::setObjetivo(const string& objetivo){
    this->objetivo.setTexto(objetivo);
}

void PlanoSprint::setCapacidade(int capacidade){
    this->capacidade.setTempo(capacidade);
}


// implementação get

string PlanoSprint::getCodigo() const{
    return codigo.getCodigo();
}

string PlanoSprint::getObjetivo() const{
    return objetivo.getTexto();
}

int PlanoSprint::getCapacidade() const{
    return capacidade.getTempo();
}