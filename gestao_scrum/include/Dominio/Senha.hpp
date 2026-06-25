#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Senha
 * @ingroup dominio
 * @brief Dominio que representa uma senha de acesso.
 *
 * Formato valido: exatamente 6 caracteres, cada um letra (a-z ou A-Z) ou
 * digito (0-9). Letra nao pode ser seguida por letra e digito nao pode ser
 * seguido por digito. Deve conter ao menos uma letra minuscula, uma letra
 * maiuscula e um digito.
 *
 * Exemplo valido: "a1B2c3". Exemplos invalidos: "abc123", "Ab1", "aaB1B2".
 */
class Senha {
    private:
        string senha; ///< Valor armazenado da senha.

        /**
         * @brief Verifica se um valor respeita o formato da senha.
         * @param senha Valor a validar.
         * @return true se valido; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui uma senha apos validacao.
         * @param senha Valor a armazenar (ex.: "a1B2c3").
         * @throw invalid_argument Se o formato for invalido (ex.: "abc123").
         */
        void setSenha(string);

        /**
         * @brief Obtem a senha armazenada.
         * @return Senha atual (ex.: retorna "a1B2c3").
         */
        string getSenha() const;
};
