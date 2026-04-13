#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Codigo {
    private:
        string codigo;
        bool validar(const string&) const;
    public:
        void setCodigo(string);
        string getCodigo() const;
};
