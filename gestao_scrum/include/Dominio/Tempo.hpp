#pragma once

#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

///Classe domínio Tempo: representa contagem em dias (1 a 365).
class Tempo {
    private:
        int tempo;
        bool validar(int) const;

    public:
        void setTempo(int);
        int getTempo() const;

};
