/**
 * @file Texto.cpp
 * @brief Implementacao do dominio Texto (ate 40 caracteres de uso geral).
 */
#include "Texto.hpp"
#include <cctype>

using namespace std;

/**
 * @brief Atribui o texto apos validar o formato.
 * @param texto Valor a armazenar (ex.: "Eu quero criar uma conta").
 * @throw invalid_argument Se o formato for invalido (ex.: " texto").
 */
void Texto::setTexto(string texto) {
    if (!validar(texto)) {
        throw invalid_argument("Texto invalido.");
    }
    this->texto = texto;
}

/**
 * @brief Obtem o texto armazenado.
 * @return Texto atual (ex.: retorna "Eu quero criar uma conta").
 */
string Texto::getTexto() const {
    return texto;
}

/**
 * @brief Valida o formato do texto.
 *
 * Regras: ate 40 caracteres; apenas letras, digitos, virgula, ponto ou espaco;
 * virgula/ponto nao seguidos por virgula ou ponto; espaco seguido por letra ou
 * digito; nao inicia nem termina com virgula, ponto ou espaco.
 * @return true para "Eu quero criar uma conta"; false para " texto" ou "fim.".
 */

///Validacoes:
///1. Texto nao pode ter mais do que 40 caracteres.
bool Texto::validar(const string& texto) const {
    if (texto.length() > 40) return false;

///2. Primeiro e ultimo caracteres nao podem ser virgula, ponto ou espaco.
    char primeiro = texto.front();
    char ultimo = texto.back();
    if (primeiro == ',' || primeiro == '.' || isspace(primeiro) || ultimo == ',' || ultimo == '.' || isspace(ultimo)) {
        return false;
    }

    for (size_t  i = 0; i < texto.length(); i++) {
        char c = texto[i];

///3. Somente pode conter letras (maiusculas e minusculas, digitos, virgula, ponto e espaco)
        if (!(isalnum(c) || c == ',' || c == '.' || isspace(c))) {
            return false;
        }

///4. Virgula nao pode ser seguida por virgula ou ponto.
        if (c == ',') {
            if (i + 1 < texto.length() && (texto[i + 1] == ',' || texto[i + 1] == '.')) {
                return false;
            }
        }
///5. Ponto nao pode ser seguido por virgula ou ponto.
        if (c == '.') {
            if(i + 1 < texto.length() && (texto[i + 1] == ',' || texto[i + 1] == '.')) {
                return false;
            }
        }

///6. Espaco em branco deve ser seguido por letra ou digito.
        if (isspace(c)) {
            if(i + 1 < texto.length() && !isalnum(texto[i + 1])) {
                return false;
            }
        }
    }
    return true;
}
