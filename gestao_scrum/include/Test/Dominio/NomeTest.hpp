#pragma once
#include "Nome.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Nome (ate 10 caracteres: letras e espacos).
class NomeTest {
    private:
        Nome* nome;
        int estado;

        const string NOME_VALIDO = "Joao Silva";

        const string NOME_INVALIDO1 = " Joao";         // inicia com espaco
        const string NOME_INVALIDO2 = "Joao ";         // termina com espaco
        const string NOME_INVALIDO3 = "Maria Antonia"; // mais de 10 caracteres
        const string NOME_INVALIDO4 = "Ana123";        // contem digitos

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
