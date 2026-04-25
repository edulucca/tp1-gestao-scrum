#include "Email.hpp"
#include <cctype>
#include <stdexcept>

using namespace std;

void Email::setEmail(string email) {
    if (!validar(email)) {
        throw invalid_argument("Email invalido: nao atende aos criterios de formato.");
    }
    this->email = email;
}

string Email::getEmail() const {
    return email;
}

bool Email::validar(const string& email) const {
    int parte_local = 0;
    int parte_dominio = 0;
    int len = email.length();
    bool arrobaFound = false;

    if (len < 3 ) return false; // tem que ter pelo menos 3 caracteres para ser um email valido (ex: a@b)
    // checa inicio e fim do email e garante que '@' nao seja o primeiro ou ultimo caractere(ou seja pelo menos um caractere antes e depois do '@')
    if (email[0] == '.' || email[0] == '-' || email[len - 1] == '.' || email[len - 1] == '-' || email[0] == '@' || email[len - 1] == '@') {
        return false;
    }
    for (int i = 0; i < len; i++) {

        char c = email[i];

        // Checa parte inicial anterior ao '@' e se ultrapassa o limite de 64 caracteres
        if ( !arrobaFound && (islower(c) || isdigit(c) || c == '.' || c == '-')) {
            parte_local++;
            if (parte_local > 64) {
                return false;
            }
            if (c == '.'  || c == '-') {
                if (!islower(email[i+1]) && !isdigit(email[i+1])) {
                    return false;
                }
            }
        // verifica se o '@' é encontrado e se ele não é precedido ou seguido por um '.' ou '-'
        } else if (!arrobaFound && c == '@') {
            arrobaFound = true;
            if (email[i-1] == '.' || email[i-1] == '-' || i + 1 >= len || email[i+1] == '.' || email[i+1] == '-') {
                return false;
            }
        } else if ( (islower(c) || isdigit(c) || c == '-' ) && arrobaFound) {
            parte_dominio++;
            if (parte_dominio > 255) {
                return false;
            }      
        } else if (c == '.' && arrobaFound) {
            parte_dominio++;
            if (parte_dominio > 255) {
                return false;
            }
            if (email[i-1] == '-' || email[i+1] == '-') {
                return false;
            }
        } else {
            return false;
        }
    }

    if (!arrobaFound || parte_local == 0 || parte_dominio == 0) {
        return false;
    }
    return true;
}
