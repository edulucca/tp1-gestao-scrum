/**
 * @file Nome.cpp
 * @brief Implementacao do dominio Nome (ate 10 caracteres: letras e espacos).
 */
#include "Nome.hpp"
#include <cctype>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @brief Valida o formato do nome.
 *
 * Regras: 1 a 10 caracteres; apenas letras (A-Z, a-z) ou espaco; nao inicia
 * nem termina com espaco; cada espaco deve ser seguido por letra.
 * @param nome Valor a validar.
 * @return true para "Luis Serra"; false para " Luis", "Luis " ou "Luis123".
 */
bool Nome::validar(const string& nome) const {
    int len = nome.length();

    if (len == 0 || len > 10) return false;
    if (nome[0] == ' ' || nome[len - 1] == ' ') return false;

    for (int i = 0; i < len; i++) {
        char c = nome[i];
        if (!isupper(c) && !islower(c) && c != ' ') return false;
        if (c == ' ' && (i + 1 >= len || !isalpha(nome[i + 1]))) return false;
    }

    return true;
}

/**
 * @brief Atribui o nome apos validar o formato.
 * @param nome Valor a armazenar (ex.: "Luis Serra").
 * @throw invalid_argument Se o formato for invalido (ex.: " Luis").
 */
void Nome::setNome(string nome) {
    int len = nome.length();

    if (len == 0) {
        throw invalid_argument("Nome invalido: o nome nao pode ser vazio.");
    }
    if (len > 10) {
        throw invalid_argument(
            "Nome invalido: maximo de 10 caracteres (informado: " + to_string(len) + ").");
    }
    if (!validar(nome)) {
        throw invalid_argument(
            "Nome invalido: use apenas letras e espacos, sem espaco no inicio ou fim.");
    }
    this->nome = nome;
}

/**
 * @brief Obtem o nome armazenado.
 * @return Nome atual (ex.: retorna "Luis Serra").
 */
string Nome::getNome() const {
    return nome;
}
