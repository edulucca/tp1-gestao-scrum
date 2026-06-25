#pragma once

#include "MSA_AuthServiceStub.hpp"

class MSC_CadastroServiceStub;

using namespace std;

/// Testa cenarios de sucesso e falha do stub MSA.
class MSA_AuthServiceStubTest {
private:
    MSA_AuthServiceStub* stub;
    MSC_CadastroServiceStub* mscStub;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};
