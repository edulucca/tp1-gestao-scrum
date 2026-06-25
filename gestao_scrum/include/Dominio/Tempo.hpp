#pragma once

#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

/**
 * @class Tempo
 * @ingroup dominio
 * @brief Dominio que representa uma contagem em dias.
 *
 * Formato valido: numero inteiro de 1 a 365.
 *
 * Exemplo valido: 30. Exemplos invalidos: 0, 366, -5.
 */
class Tempo {
    private:
        int tempo; ///< Valor armazenado em dias.

        /**
         * @brief Verifica se um valor esta no intervalo permitido.
         * @param tempo Valor a validar.
         * @return true se estiver entre 1 e 365; false caso contrario.
         */
        bool validar(int) const;

    public:
        /**
         * @brief Atribui uma quantidade de dias apos validacao.
         * @param tempo Valor a armazenar (ex.: 30).
         * @throw invalid_argument Se estiver fora do intervalo 1 a 365 (ex.: 0).
         */
        void setTempo(int);

        /**
         * @brief Obtem a quantidade de dias armazenada.
         * @return Numero de dias atual (ex.: retorna 30).
         */
        int getTempo() const;

};
