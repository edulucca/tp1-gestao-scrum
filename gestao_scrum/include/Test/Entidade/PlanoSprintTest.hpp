#pragma once
#include "PlanoSprint.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha da entidade PlanoSprint.
class PlanoSprintTest {
    private:
        PlanoSprint* plano;
        int estado;

        const string CODIGO_VALIDO = "PS100";
        const string OBJETIVO_VALIDO = "Entregar o cadastro de contas";
        const int CAPACIDADE_VALIDA = 15;

        const string CODIGO_INVALIDO = "ps100";        // letras minusculas
        const string OBJETIVO_INVALIDO = " objetivo";  // inicia com espaco
        const int CAPACIDADE_INVALIDA = 0;             // fora de 1..365

        const string OUTRO_CODIGO_VALIDO = "PS200";

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
