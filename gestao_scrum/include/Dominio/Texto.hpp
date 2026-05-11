#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Texto {
    private:
        string texto;
        bool validar(const string&) const;
    public:
        void setTexto(string);
        string getTexto() const;
};
