#pragma once
#include "Papel.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Papel (DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO).
class PapelTest {
    private:
        Papel* papel;
        int estado;

        const string PAPEL_VALIDO = "MESTRE SCRUM";

        const string PAPEL_INVALIDO1 = "GERENTE";       // papel inexistente
        const string PAPEL_INVALIDO2 = "desenvolvedor"; // caixa incorreta
        const string PAPEL_INVALIDO3 = "";              // vazio

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
