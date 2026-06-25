#pragma once

#include "MSC_CadastroServiceStub.hpp"
#include "Pessoa.hpp"

using namespace std;

/// Testa cenarios de sucesso, falha e listagem do stub MSC.
class MSC_CadastroServiceStubTest {
private:
    MSC_CadastroServiceStub* stub;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void testarListarPessoasSucesso();
    void testarListarPessoasAposCadastro();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};
