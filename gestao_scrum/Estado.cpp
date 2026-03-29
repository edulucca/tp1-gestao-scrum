#include "Estado.hpp"

void Estado::setEstado(string estado){
    if(estado != A_FAZER || estado != FAZENDO || estado != FEITO){

    }
    this->estado = estado;
}
