#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED
#include <iostream>

using namespace std;

class Estado {
    private:
        static const string A_FAZER = "A FAZER";
        static const string FAZENDO = "FAZENDO";
        static const string FEITO = "FEITO";

        string estado;
    public:
        void setEstado(string);
};


#endif // ESTADO_HPP_INCLUDED
