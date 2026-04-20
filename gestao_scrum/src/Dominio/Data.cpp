#include "Data.hpp"
#include <cctype>
#include <stdexcept>

using namespace std;

bool Data::validar(const string& data) const {
    int len = data.length();

    if (len != 9 && len != 10) return false;
    int dia;
    int mes;
    int ano;
    if (data[2] == '/' ){ // Formato dd/mm/yyyy
        try {
            dia = stoi(data.substr(0, 2));
            mes = stoi(data.substr(3, 2));
            ano = stoi(data.substr(6, 4));
        } catch (const invalid_argument& error) {
            return false;
        }
    } else if (data[1] == '/' ){ // Formato d/m/yyyy
        try {
            dia = stoi(data.substr(0, 1));
            mes = stoi(data.substr(2, 2));
            ano = stoi(data.substr(5, 4));
        } catch (const invalid_argument& error) {
            return false;
        }
    } else {
        return false;
    }
    if (ano < 2000 || ano > 2999) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1) return false;
    if (mes == 2) {
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (dia > (bissexto ? 29 : 28)) return false;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) return false;
    } else {
        if (dia > 31) return false;
    }
    return true;
}

void Data::setData(string data) {
    if (!validar(data)) {
        throw invalid_argument("Data invalida: nao atende aos criterios de formato.");
    }
    this->data = data;
}

string Data::getData() const {
    return data;
}