#pragma once
#include "Senha.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Senha (6 caracteres alternando letra/digito).
class SenhaTest {
    private:
        Senha* senha;
        int estado;

        const string SENHA_VALIDA = "a1B2c3";

        const string SENHA_INVALIDA1 = "abc123"; // letras consecutivas
        const string SENHA_INVALIDA2 = "a1b2c3"; // sem letra maiuscula
        const string SENHA_INVALIDA3 = "A1B2C3"; // sem letra minuscula
        const string SENHA_INVALIDA4 = "a1B2c";  // menos de 6 caracteres

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
