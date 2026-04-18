#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Estado {
    private:
        static const string A_FAZER;
        static const string FAZENDO;
        static const string FEITO;

        string estado;
    public:
        void setEstado(string);
        string getEstado() const;
        bool validar(const string&) const;
};
