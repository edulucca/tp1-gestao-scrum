/**
 * @file Estado.cpp
 * @brief Implementacao do dominio Estado (A FAZER, FAZENDO, FEITO).
 */
#include "Estado.hpp"

using namespace std;

const string Estado::A_FAZER = "A FAZER"; ///< Texto do estado "A FAZER".
const string Estado::FAZENDO = "FAZENDO"; ///< Texto do estado "FAZENDO".
const string Estado::FEITO = "FEITO";     ///< Texto do estado "FEITO".

/**
 * @brief Atribui o estado apos validar o valor.
 * @throw invalid_argument Se nao for "A FAZER", "FAZENDO" ou "FEITO".
 */
void Estado::setEstado(string estado){
    if(!validar(estado)){
        throw invalid_argument("Estado invalido");
    }
    this->estado = estado;
}

/**
 * @brief Valida se o valor e um dos estados aceitos.
 * @param estado Valor a validar.
 * @return true para "FEITO"; false para "EM ANDAMENTO" ou "feito".
 */
bool Estado::validar(const string& estado) const {
    return estado == A_FAZER || estado == FAZENDO || estado == FEITO;
}

/**
 * @brief Obtem o estado armazenado.
 * @return Estado atual (ex.: retorna "FAZENDO").
 */
string Estado::getEstado() const {
    return estado;
}
