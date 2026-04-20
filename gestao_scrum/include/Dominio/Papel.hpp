#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Papel {
    private:
        static const string DESENVOLVEDOR;
        static const string MESTRE_SCRUM;
        static const string PROPRIETARIO_DE_PRODUTO;

        string papel;
    public:
        void setPapel(string);
        string getPapel() const;
        bool validar(const string&) const;
};
