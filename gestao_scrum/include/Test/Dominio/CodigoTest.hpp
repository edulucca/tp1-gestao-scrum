#pragma once
#include "Codigo.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Codigo (2 letras maiusculas + 3 digitos).
class CodigoTest {
    private:
        Codigo* codigo;
        int estado;

        const string CODIGO_VALIDO = "AB123";

        const string CODIGO_INVALIDO1 = "ab123"; // letras minusculas
        const string CODIGO_INVALIDO2 = "A1234"; // apenas uma letra
        const string CODIGO_INVALIDO3 = "AB12";  // menos de 5 caracteres
        const string CODIGO_INVALIDO4 = "AB1234"; // mais de 5 caracteres

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
