/**
 * @file Prioridade.cpp
 * @brief Implementacao do dominio Prioridade (ALTA, MEDIA, BAIXA).
 */
#include "Prioridade.hpp"

using namespace std;

const string Prioridade::ALTA = "ALTA";   ///< Texto da prioridade alta.
const string Prioridade::MEDIA = "MEDIA"; ///< Texto da prioridade media.
const string Prioridade::BAIXA = "BAIXA"; ///< Texto da prioridade baixa.

/**
 * @brief Atribui a prioridade apos validar o valor.
 * @throw invalid_argument Se nao for "ALTA", "MEDIA" ou "BAIXA".
 */
void Prioridade::setPrioridade(string prioridade){
    if(!validar(prioridade)){
        throw invalid_argument("Prioridade invalida");
    }
    this->prioridade = prioridade;
}

/**
 * @brief Valida se o valor e uma das prioridades aceitas.
 * @param prioridade Valor a validar.
 * @return true para "ALTA"; false para "URGENTE" ou "alta".
 */
bool Prioridade::validar(const string& prioridade) const {
    return prioridade == ALTA || prioridade == MEDIA || prioridade == BAIXA;
}

/**
 * @brief Obtem a prioridade armazenada.
 * @return Prioridade atual (ex.: retorna "ALTA").
 */
string Prioridade::getPrioridade() const {
    return prioridade;
}
