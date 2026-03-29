#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Estado {
    private:
        static const string A_FAZER;
        static const string FAZENDO;
        static const string FEITO;

        string estado;
    public:
        void setEstado(string);
};


#endif // ESTADO_HPP_INCLUDED
