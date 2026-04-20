#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Prioridade {
    private:
        static const string ALTA;
        static const string MEDIA;
        static const string BAIXA;

        string prioridade;
    public:
        void setPrioridade(string);
        string getPrioridade() const;
        bool validar(const string&) const;
};
