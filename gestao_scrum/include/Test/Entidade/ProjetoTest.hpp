#pragma once
#include "Projeto.hpp"

using namespace std;

class ProjetoTest {
    private:
        Projeto* projeto;
        int estado;
        const string NOME_VALIDO = "Sis Scrum";
        const string NOME_INVALIDO = " Sis Scrum";

        const string DATA_VALIDA = "15/10/2024";
        const string DATA_VALIDA_FIM = "15/11/2024";
        const string DATA_INVALIDA = "32/13/3000";

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
