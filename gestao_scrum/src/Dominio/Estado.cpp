#include "Estado.hpp"

using namespace std;

const string Estado::A_FAZER = "A FAZER";
const string Estado::FAZENDO = "FAZENDO";
const string Estado::FEITO = "FEITO";

void Estado::setEstado(string estado){
    if(!validar(estado)){
        throw invalid_argument("Estado invalido");
    }
    this->estado = estado;
}

bool Estado::validar(const string& estado) const {
    return estado == A_FAZER || estado == FAZENDO || estado == FEITO;
}

string Estado::getEstado() const {
    return estado;
}