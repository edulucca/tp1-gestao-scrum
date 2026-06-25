#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Data
 * @ingroup dominio
 * @brief Dominio que representa uma data no formato DIA/MES/ANO.
 *
 * Formato valido: "DD/MM/AAAA", com DIA de 1 a 31, MES de 01 a 12 e
 * ANO de 2000 a 2999. A data deve ser real, considerando anos bissextos.
 *
 * Exemplo valido: "29/02/2024". Exemplos invalidos: "29/02/2023", "31/04/2025".
 */
class Data {
    private:
        string data; ///< Valor armazenado da data.

        /**
         * @brief Verifica se um valor respeita o formato da data.
         * @param data Valor a validar.
         * @return true se valido; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui uma data apos validacao.
         * @param data Valor a armazenar (ex.: "29/02/2024").
         * @throw invalid_argument Se o formato for invalido (ex.: "31/04/2025").
         */
        void setData(string);

        /**
         * @brief Obtem a data armazenada.
         * @return Data atual (ex.: retorna "29/02/2024").
         */
        string getData() const;
};
