#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Nome {
    private:
        string nome;
        bool validar(const string&) const;
    public:
        void setNome(string);
        string getNome() const;
};
