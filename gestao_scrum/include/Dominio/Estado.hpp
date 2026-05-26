#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Estado
 * @brief Dominio que representa o estado de uma historia de usuario.
 *
 * Valores validos (unicos aceitos): "A FAZER", "FAZENDO", "FEITO".
 *
 * Exemplo valido: "FAZENDO". Exemplos invalidos: "EM ANDAMENTO", "feito".
 */
class Estado {
    private:
        static const string A_FAZER; ///< Constante do estado "A FAZER".
        static const string FAZENDO; ///< Constante do estado "FAZENDO".
        static const string FEITO;   ///< Constante do estado "FEITO".

        string estado; ///< Valor armazenado do estado.

        /**
         * @brief Verifica se um valor e um estado valido.
         * @param estado Valor a validar.
         * @return true se for "A FAZER", "FAZENDO" ou "FEITO"; false caso contrario.
         */
        bool validar(const string&) const;

    public:
        /**
         * @brief Atribui um estado apos validacao.
         * @param estado Valor a armazenar (ex.: "FAZENDO").
         * @throw invalid_argument Se o valor nao for "A FAZER", "FAZENDO" ou "FEITO".
         */
        void setEstado(string);

        /**
         * @brief Obtem o estado armazenado.
         * @return Estado atual (ex.: retorna "FAZENDO").
         */
        string getEstado() const;
};
