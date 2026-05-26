#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Papel
 * @brief Dominio que representa o papel (role) de uma pessoa no projeto.
 *
 * Valores validos (unicos aceitos): "DESENVOLVEDOR", "MESTRE SCRUM",
 * "PROPRIETARIO DE PRODUTO".
 *
 * Exemplo valido: "MESTRE SCRUM". Exemplos invalidos: "GERENTE", "desenvolvedor".
 */
class Papel {
    private:
        static const string DESENVOLVEDOR;           ///< Constante "DESENVOLVEDOR".
        static const string MESTRE_SCRUM;            ///< Constante "MESTRE SCRUM".
        static const string PROPRIETARIO_DE_PRODUTO; ///< Constante "PROPRIETARIO DE PRODUTO".

        string papel; ///< Valor armazenado do papel.

        /**
         * @brief Verifica se um valor e um papel valido.
         * @param papel Valor a validar.
         * @return true se for um dos papeis aceitos; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui um papel apos validacao.
         * @param papel Valor a armazenar (ex.: "MESTRE SCRUM").
         * @throw invalid_argument Se o valor nao for um papel aceito (ex.: "GERENTE").
         */
        void setPapel(string);

        /**
         * @brief Obtem o papel armazenado.
         * @return Papel atual (ex.: retorna "MESTRE SCRUM").
         */
        string getPapel() const;
};
