#include "Tempo.hpp"

using namespace std;

void Tempo::setTempo(int tempo) {
    if (!validar(tempo)) {
        throw invalid_argument("Tempo inválido: deve ser entre 1 e 365 dias.");
    }
    this->tempo = tempo;
}

int Tempo::getTempo() const {
    return tempo;
}

bool Tempo::validar(int tempo) const {
    return (tempo >= 1 && tempo <= 365);
}
