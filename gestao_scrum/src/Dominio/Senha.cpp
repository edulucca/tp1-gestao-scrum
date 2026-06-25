/**
 * @file Senha.cpp
 * @brief Implementacao do dominio Senha (6 caracteres alternando letra/digito).
 */
#include "Senha.hpp"
#include <cctype>
#include <string>

using namespace std;

/**
 * @brief Atribui a senha apos validar o formato.
 * @param senha Valor a armazenar (ex.: "a1B2c3").
 * @throw invalid_argument Se o formato for invalido (ex.: "abc123").
 */
void Senha::setSenha(string senha) {
    if (senha.length() != 6) {
        throw invalid_argument(
            "Senha invalida: deve ter exatamente 6 caracteres (informado: "
            + to_string(senha.length()) + ").");
    }
    if (!validar(senha)) {
        throw invalid_argument(
            "Senha invalida: alterne letras e digitos e inclua minuscula, maiuscula e digito.");
    }
    this->senha = senha;
}

/**
 * @brief Obtem a senha armazenada.
 * @return Senha atual (ex.: retorna "a1B2c3").
 */
string Senha::getSenha() const {
    return senha;
}

/**
 * @brief Valida o formato da senha.
 *
 * Regras: exatamente 6 caracteres (letras ou digitos); letra nao seguida por
 * letra e digito nao seguido por digito; ao menos uma minuscula, uma maiuscula
 * e um digito.
 * @param s Valor a validar.
 * @return true para "a1B2c3"; false para "abc123", "Ab1" ou "aaB1B2".
 */
bool Senha::validar(const string& s) const {
    if (s.length() != 6) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false;

    for (int i = 0; i < 6; i++) {
        char c = s[i];
        if (!isalpha(c) && !isdigit(c)) return false;

        if (i < 5) {
            char next = s[i + 1];
            if (isalpha(c) && isalpha(next)) return false;
            if (isdigit(c) && isdigit(next)) return false;
        }

        if (islower(c)) hasLower = true;
        if (isupper(c)) hasUpper = true;
        if (isdigit(c)) hasDigit = true;
    }

    return hasLower && hasUpper && hasDigit;
}
