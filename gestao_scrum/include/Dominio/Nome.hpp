#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Nome
 * @ingroup dominio
 * @brief Dominio que representa um nome de pessoa.
 *
 * Formato valido: ate 10 caracteres, contendo letras maiusculas (A-Z),
 * minusculas (a-z) ou espaco em branco. Cada espaco deve ser seguido por
 * letra; o primeiro e o ultimo caractere nao podem ser espaco.
 *
 * Exemplo valido: "Luis Serra". Exemplos invalidos: " Luis", "Luis ", "Lui123".
 */
class Nome {
    private:
        string nome; ///< Valor armazenado do nome.

        /**
         * @brief Verifica se um valor respeita o formato do nome.
         * @param nome Valor a validar.
         * @return true se valido; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui um nome apos validacao.
         * @param nome Valor a armazenar (ex.: "Luis Serra").
         * @throw invalid_argument Se o formato for invalido (ex.: " Luis").
         */
        void setNome(string);

        /**
         * @brief Obtem o nome armazenado.
         * @return Nome atual (ex.: retorna "Luis Serra").
         */
        string getNome() const;
};
