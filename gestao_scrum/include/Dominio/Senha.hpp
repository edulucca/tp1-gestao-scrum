#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Senha {
    private:
        string senha;
        bool validar(const string&) const;
    public:
        void setSenha(string);
        string getSenha() const;
};
