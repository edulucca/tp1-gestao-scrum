#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Texto
 * @ingroup dominio
 * @brief Dominio que representa um texto curto de uso geral.
 *
 * Formato valido: ate 40 caracteres, contendo letras (a-z, A-Z), digitos (0-9),
 * virgula, ponto ou espaco. Virgula nao pode ser seguida por virgula ou ponto;
 * ponto nao pode ser seguido por virgula ou ponto; espaco deve ser seguido por
 * letra ou digito; o primeiro e o ultimo caractere nao podem ser virgula, ponto
 * ou espaco.
 *
 * Exemplo valido: "Eu quero criar uma conta". Exemplos invalidos: " texto", "fim.".
 */
class Texto {
    private:
        string texto; ///< Valor armazenado do texto.

        /**
         * @brief Verifica se um valor respeita o formato do texto.
         * @param texto Valor a validar.
         * @return true se valido; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui um texto apos validacao.
         * @param texto Valor a armazenar (ex.: "Eu quero criar uma conta").
         * @throw invalid_argument Se o formato for invalido (ex.: " texto").
         */
        void setTexto(string);

        /**
         * @brief Obtem o texto armazenado.
         * @return Texto atual (ex.: retorna "Eu quero criar uma conta").
         */
        string getTexto() const;
};
