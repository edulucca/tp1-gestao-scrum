#pragma once
#include "Tempo.hpp"

using namespace std;

///Classe que testa os cen�rios de sucesso e falha da classe-dominio "Tempo".
class TempoTest {
    private:
        Tempo* tempo;
        int estado;

        const static int SUCESSO = 0;
        const static int FALHA = -1;

        const int TEMPO_VALIDO1 = 1;
        const int TEMPO_VALIDO2 = 100;
        const int TEMPO_VALIDO3 = 365;

        const int TEMPO_INVALIDO1 = 0;
        const int TEMPO_INVALIDO2 = 366;
        const int TEMPO_INVALIDO3 = -10;

    public:
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
        int run();
};
