/**
 * @file Papel.cpp
 * @brief Implementacao do dominio Papel (DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO).
 */
#include "Papel.hpp"

using namespace std;

const string Papel::DESENVOLVEDOR = "DESENVOLVEDOR";                     ///< Texto do papel desenvolvedor.
const string Papel::MESTRE_SCRUM = "MESTRE SCRUM";                       ///< Texto do papel mestre scrum.
const string Papel::PROPRIETARIO_DE_PRODUTO = "PROPRIETARIO DE PRODUTO"; ///< Texto do papel proprietario de produto.

/**
 * @brief Atribui o papel apos validar o valor.
 * @throw invalid_argument Se nao for um dos papeis aceitos (ex.: "GERENTE").
 */
void Papel::setPapel(string papel){
    if(!validar(papel)){
        throw invalid_argument("Papel invalido");
    }
    this->papel = papel;
}

/**
 * @brief Valida se o valor e um dos papeis aceitos.
 * @param papel Valor a validar.
 * @return true para "MESTRE SCRUM"; false para "GERENTE" ou "desenvolvedor".
 */
bool Papel::validar(const string& papel) const {
    return papel == DESENVOLVEDOR || papel == MESTRE_SCRUM || papel == PROPRIETARIO_DE_PRODUTO;
}

/**
 * @brief Obtem o papel armazenado.
 * @return Papel atual (ex.: retorna "MESTRE SCRUM").
 */
string Papel::getPapel() const {
    return papel;
}
