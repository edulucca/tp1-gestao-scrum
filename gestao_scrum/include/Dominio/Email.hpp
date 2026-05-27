#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Email
 * @brief Dominio que representa um endereco de email no formato parte-local\@dominio.
 *
 * Parte local: letras (a-z), digitos (0-9), ponto ou hifen; nao pode iniciar
 * nem terminar com ponto ou hifen; ponto/hifen deve ser seguido por letra ou
 * digito; comprimento maximo 64.
 * Dominio: uma ou mais partes separadas por ponto; cada parte com letras (a-z),
 * digitos (0-9) ou hifen; nao pode iniciar nem terminar com hifen; maximo 255.
 *
 * Exemplo valido: "luis.serra@unb.br". Exemplos invalidos: ".luis@unb.br", "luis@-unb.br".
 */
class Email {
    private:
        string email; ///< Valor armazenado do email.

        /**
         * @brief Verifica se um valor respeita o formato do email.
         * @param email Valor a validar.
         * @return true se valido; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui um email apos validacao.
         * @param email Valor a armazenar (ex.: "joao.silva@unb.br").
         * @throw invalid_argument Se o formato for invalido (ex.: ".luis@unb.br").
         */
        void setEmail(string);

        /**
         * @brief Obtem o email armazenado.
         * @return Email atual (ex.: retorna "luis.serra@unb.br").
         */
        string getEmail() const;
};
