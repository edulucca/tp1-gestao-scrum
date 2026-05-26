#pragma once
#include "Prioridade.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Prioridade (ALTA, MEDIA, BAIXA).
class PrioridadeTest {
    private:
        Prioridade* prioridade;
        int estado;

        const string PRIORIDADE_VALIDA = "MEDIA";

        const string PRIORIDADE_INVALIDA1 = "URGENTE"; // valor inexistente
        const string PRIORIDADE_INVALIDA2 = "alta";    // caixa incorreta
        const string PRIORIDADE_INVALIDA3 = "";        // vazio

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
