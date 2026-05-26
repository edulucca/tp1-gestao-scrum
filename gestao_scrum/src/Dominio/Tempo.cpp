/**
 * @file Tempo.cpp
 * @brief Implementacao do dominio Tempo (contagem em dias de 1 a 365).
 */
#include "Tempo.hpp"

using namespace std;

/**
 * @brief Atribui a quantidade de dias apos validar o intervalo.
 * @throw invalid_argument Se estiver fora de 1 a 365 (ex.: 0 ou 366).
 */
void Tempo::setTempo(int tempo) {
    if (!validar(tempo)) {
        throw invalid_argument("Tempo inv�lido: deve ser entre 1 e 365 dias.");
    }
    this->tempo = tempo;
}

/**
 * @brief Obtem a quantidade de dias armazenada.
 * @return Numero de dias atual (ex.: retorna 30).
 */
int Tempo::getTempo() const {
    return tempo;
}

/**
 * @brief Valida se o numero de dias esta no intervalo permitido.
 * @param tempo Valor a validar.
 * @return true para 30; false para 0 ou 366.
 */
bool Tempo::validar(int tempo) const {
    return (tempo >= 1 && tempo <= 365);
}
