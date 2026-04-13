#include "Codigo.hpp"
#include <cctype>
#include <iostream>

using namespace std;

void Codigo::setCodigo(string codigo){
    if(!validar(codigo)){
        throw invalid_argument("Codigo invalido");
    }
    this->codigo = codigo;
}

bool Codigo::validar(const string& palavra) const {
    if (palavra.length() != 5) {
        return false;
    }

    if (!isupper(palavra[0]) || !isupper(palavra[1])) {
        return false;
    }

    if (!isdigit(palavra[2]) || !isdigit(palavra[3]) || !isdigit(palavra[4])) {
        return false;
    }

    return true;
}

string Codigo::getCodigo() const {
    return codigo;
}
