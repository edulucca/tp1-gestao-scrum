#include "Nome.hpp"
#include <cctype>
#include <stdexcept>

using namespace std;

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

void Nome::setNome(string nome) {
    if (!validar(nome)) {
        throw invalid_argument("Nome invalido: nao atende aos criterios de formato.");
    }
    this->nome = nome;
}

string Nome::getNome() const {
    return nome;
}