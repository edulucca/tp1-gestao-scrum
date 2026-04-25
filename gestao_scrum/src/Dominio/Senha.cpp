#include "Senha.hpp"
#include <cctype>

using namespace std;

void Senha::setSenha(string senha) {
    if (!validar(senha)) {
        throw invalid_argument("Senha invalida.");
    }
    this->senha = senha;
}

string Senha::getSenha() const {
    return senha;
}

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
