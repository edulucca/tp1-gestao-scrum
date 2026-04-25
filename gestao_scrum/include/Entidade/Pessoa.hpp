#pragma once
#include <string>

using namespace std;

class Pessoa {
    private:
        class Impl;
        Impl* impl;

    public:
        Pessoa();
        ~Pessoa();

        void setEmail(const string&);
        void setNome(const string&);
        void setSenha(const string&);
        void setPapel(const string&);

        string getEmail() const;
        string getNome() const;
        string getSenha() const;
        string getPapel() const;
};
