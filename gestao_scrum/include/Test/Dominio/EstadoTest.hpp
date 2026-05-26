#pragma once
#include "Estado.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Estado (A FAZER, FAZENDO, FEITO).
class EstadoTest {
    private:
        Estado* estadoObj;
        int estado;

        const string ESTADO_VALIDO = "FAZENDO";

        const string ESTADO_INVALIDO1 = "EM ANDAMENTO"; // valor inexistente
        const string ESTADO_INVALIDO2 = "feito";        // caixa incorreta
        const string ESTADO_INVALIDO3 = "";             // vazio

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
