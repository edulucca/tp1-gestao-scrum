#include "Prioridade.hpp"

using namespace std;

const string Prioridade::ALTA = "ALTA";
const string Prioridade::MEDIA = "MEDIA";
const string Prioridade::BAIXA = "BAIXA";

void Prioridade::setPrioridade(string prioridade){
    if(!validar(prioridade)){
        throw invalid_argument("Prioridade invalida");
    }
    this->prioridade = prioridade;
}

bool Prioridade::validar(const string& prioridade) const {
    return prioridade == ALTA || prioridade == MEDIA || prioridade == BAIXA;
}

string Prioridade::getPrioridade() const {
    return prioridade;
}