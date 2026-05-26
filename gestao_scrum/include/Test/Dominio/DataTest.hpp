#pragma once
#include "Data.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha do dominio Data (DIA/MES/ANO, com anos bissextos).
class DataTest {
    private:
        Data* data;
        int estado;

        const string DATA_VALIDA = "15/10/2024";

        const string DATA_INVALIDA1 = "32/13/2024"; // dia e mes fora do intervalo
        const string DATA_INVALIDA2 = "31/04/2025"; // abril nao tem 31 dias
        const string DATA_INVALIDA3 = "29/02/2023"; // ano nao bissexto
        const string DATA_INVALIDA4 = "1510/2024";  // formato sem barras

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
