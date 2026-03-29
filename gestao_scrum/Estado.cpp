#include "Estado.hpp"

using namespace std;

const string Estado::A_FAZER = "A FAZER";
const string Estado::FAZENDO = "FAZENDO";
const string Estado::FEITO = "FEITO";

void Estado::setEstado(string estado){
    if(estado != A_FAZER || estado != FAZENDO || estado != FEITO){

    }
    this->estado = estado;
}
