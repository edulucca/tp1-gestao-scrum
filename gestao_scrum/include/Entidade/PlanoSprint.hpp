#pragma once
#include <string>

// include dos dominios

#include "Codigo.hpp"
#include "Texto.hpp"
#include "Tempo.hpp"

using namespace std;

class PlanoSprint{
    private:
        Codigo codigo;
        Texto objetivo;
        Tempo capacidade;

    public:

        // constrtores e destrutores

        PlanoSprint();
        ~PlanoSprint();

        // metodos set

        void setCodigo(const string&);
        void setObjetivo(const string&);
        void setCapacidade(int); 

        // metodos get

        string getCodigo() const;
        string getObjetivo() const;
        int getCapacidade() const;
};