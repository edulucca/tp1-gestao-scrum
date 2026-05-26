#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Prioridade
 * @brief Dominio que representa a prioridade de uma historia de usuario.
 *
 * Valores validos (unicos aceitos): "ALTA", "MEDIA", "BAIXA".
 *
 * Exemplo valido: "ALTA". Exemplos invalidos: "URGENTE", "alta".
 */
class Prioridade {
    private:
        static const string ALTA;  ///< Constante da prioridade "ALTA".
        static const string MEDIA; ///< Constante da prioridade "MEDIA".
        static const string BAIXA; ///< Constante da prioridade "BAIXA".

        string prioridade; ///< Valor armazenado da prioridade.

        /**
         * @brief Verifica se um valor e uma prioridade valida.
         * @param prioridade Valor a validar.
         * @return true se for "ALTA", "MEDIA" ou "BAIXA"; false caso contrario.
         */
        bool validar(const string&) const;
    public:
        /**
         * @brief Atribui uma prioridade apos validacao.
         * @param prioridade Valor a armazenar (ex.: "ALTA").
         * @throw invalid_argument Se o valor nao for "ALTA", "MEDIA" ou "BAIXA".
         */
        void setPrioridade(string);

        /**
         * @brief Obtem a prioridade armazenada.
         * @return Prioridade atual (ex.: retorna "ALTA").
         */
        string getPrioridade() const;
};
