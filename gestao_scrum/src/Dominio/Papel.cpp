#include "Papel.hpp"

using namespace std;

const string Papel::DESENVOLVEDOR = "DESENVOLVEDOR";
const string Papel::MESTRE_SCRUM = "MESTRE SCRUM";
const string Papel::PROPRIETARIO_DE_PRODUTO = "PROPRIETARIO DE PRODUTO";

void Papel::setPapel(string papel){
    if(!validar(papel)){
        throw invalid_argument("Papel invalido");
    }
    this->papel = papel;
}

bool Papel::validar(const string& papel) const {
    return papel == DESENVOLVEDOR || papel == MESTRE_SCRUM || papel == PROPRIETARIO_DE_PRODUTO;
}

string Papel::getPapel() const {
    return papel;
}