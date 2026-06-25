#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Codigo
 * @ingroup dominio
 * @brief Dominio que representa um codigo identificador.
 *
 * Formato valido: exatamente 5 caracteres, sendo os 2 primeiros letras
 * maiusculas (A-Z) e os 3 ultimos digitos (0-9).
 *
 * Exemplo valido: "AB123". Exemplos invalidos: "ab123", "A1234", "ABC12".
 */
class Codigo {
    private:
        string codigo; ///< Valor armazenado do codigo.

        /**
         * @brief Verifica se um valor respeita o formato do codigo.
         * @param codigo Valor a validar.
         * @return true se valido; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui um codigo apos validacao.
         * @param codigo Valor a armazenar (ex.: "AB123").
         * @throw invalid_argument Se o formato for invalido (ex.: "ab123").
         */
        void setCodigo(string);

        /**
         * @brief Obtem o codigo armazenado.
         * @return Codigo atual (ex.: retorna "AB123").
         */
        string getCodigo() const;
};
