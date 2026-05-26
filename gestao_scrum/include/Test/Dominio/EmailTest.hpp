#pragma once
#include "Email.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Email (parte-local\@dominio).
class EmailTest {
    private:
        Email* email;
        int estado;

        const string EMAIL_VALIDO = "joao.silva@unb.br";

        const string EMAIL_INVALIDO1 = ".joao@unb.br"; // inicia com ponto
        const string EMAIL_INVALIDO2 = "joaosilva.br";  // sem arroba
        const string EMAIL_INVALIDO3 = "@unb.br";        // sem parte local
        const string EMAIL_INVALIDO4 = "joao@unb-.br";   // parte do dominio termina em hifen

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
