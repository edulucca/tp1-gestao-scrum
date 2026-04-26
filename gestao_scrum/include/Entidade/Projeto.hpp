#pragma once
#include <string>

using namespace std;

class Projeto {
    private:
        class Impl;
        Impl* impl;

    public:
        Projeto();
        ~Projeto();

        void setNome(const string&);
        void setDataInicio(const string&);
        void setDataTermino(const string&);

        string getNome() const;
        string getDataInicio() const;
        string getDataTermino() const;
};
