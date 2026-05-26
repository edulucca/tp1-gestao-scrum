/**
 * @file Codigo.cpp
 * @brief Implementacao do dominio Codigo (2 letras maiusculas + 3 digitos).
 */
#include "Codigo.hpp"
#include <cctype>
#include <iostream>

using namespace std;

/**
 * @brief Atribui o codigo apos validar o formato.
 * @param codigo Valor a armazenar (ex.: "AB123").
 * @throw invalid_argument Se o formato for invalido (ex.: "ab123").
 */
void Codigo::setCodigo(string codigo){
    if(!validar(codigo)){
        throw invalid_argument("Codigo invalido");
    }
    this->codigo = codigo;
}

/**
 * @brief Valida o formato: 5 caracteres, 2 letras maiusculas seguidas de 3 digitos.
 * @param palavra Valor a validar.
 * @return true para "AB123"; false para "ab123", "A1234" ou "ABC12".
 */
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

/**
 * @brief Obtem o codigo armazenado.
 * @return Codigo atual (ex.: retorna "AB123").
 */
string Codigo::getCodigo() const {
    return codigo;
}
