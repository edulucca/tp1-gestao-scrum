#include "Texto.hpp"
#include <cctype>

using namespace std;

void Texto::setTexto(string texto) {
    if (!validar(texto)) {
        throw invalid_argument("Texto invalido.");
    }
    this->texto = texto;
}

string Texto::getTexto() const {
    return texto;
}

///Validações:
///1. Texto não pode ter mais do que 40 caracteres.
bool Texto::validar(const string& texto) const {
    if (texto.length() > 40) return false;

///2. Primeiro e último caracteres não podem ser vírgula, ponto ou espaço.
    char primeiro = texto.front();
    char ultimo = texto.back();
    if (primeiro == ',' || primeiro == '.' || isspace(primeiro) || ultimo == ',' || ultimo == '.' || isspace(ultimo)) {
        return false;
    }

    for (size_t  i = 0; i < texto.length(); i++) {
        char c = texto[i];

///3. Somente pode conter letras (maiúsculas e minúsculas, dígitos, vírgula, ponto e espaço)
        if (!(isalnum(c) || c == ',' || c == '.' || isspace(c))) {
            return false;
        }

///4. Vírgula não pode ser seguida por vírgula ou ponto.
        if (c == ',') {
            if (i + 1 < texto.length() && (texto[i + 1] == ',' || texto[i + 1] == '.')) {
                return false;
            }
        }
///5. Ponto não pode ser seguido por vírgula ou ponto.
        if (c == '.') {
            if(i + 1 < texto.length() && (texto[i + 1] == ',' || texto[i + 1] == '.')) {
                return false;
            }
        }

///6. Espaço em branco deve ser seguido por letra ou dígito.
        if (isspace(c)) {
            if(i + 1 < texto.length() && !isalnum(texto[i + 1])) {
                return false;
            }
        }
    }
            return true;
