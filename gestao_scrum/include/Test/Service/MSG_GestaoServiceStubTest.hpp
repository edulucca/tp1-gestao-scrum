#pragma once

#include "MSG_GestaoServiceStub.hpp"

using namespace std;

class MSG_GestaoServiceStubTest {
private:
    MSG_GestaoServiceStub* stub;
    int estado;

    void setUp();
    void tearDown();
    void testarListarHistoriasPorProjeto();
    void testarAlterarEstadoHistoria();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};
