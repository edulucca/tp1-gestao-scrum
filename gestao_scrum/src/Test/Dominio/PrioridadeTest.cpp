#include "PrioridadeTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void PrioridadeTest::setUp() {
    prioridade = new Prioridade();
    estado = SUCESSO;
}

void PrioridadeTest::tearDown() {
    delete prioridade;
}

void PrioridadeTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setPrioridade(" << PRIORIDADE_VALIDA << ")" << endl;
        prioridade->setPrioridade(PRIORIDADE_VALIDA);
        assert(prioridade->getPrioridade() == PRIORIDADE_VALIDA);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void PrioridadeTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setPrioridade(" << PRIORIDADE_INVALIDA1 << ")" << endl;
        prioridade->setPrioridade(PRIORIDADE_INVALIDA1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou prioridade invalida (inexistente)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setPrioridade(" << PRIORIDADE_INVALIDA2 << ")" << endl;
        prioridade->setPrioridade(PRIORIDADE_INVALIDA2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou prioridade invalida (caixa incorreta)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setPrioridade(" << PRIORIDADE_INVALIDA3 << ")" << endl;
        prioridade->setPrioridade(PRIORIDADE_INVALIDA3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou prioridade invalida (vazio)." << endl;
    } catch (invalid_argument&) {}
}

int PrioridadeTest::run() {
    cout << "Rodando testes do dominio Prioridade..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Prioridade: OK!" << endl;
    } else {
        cout << "-> Testes de Prioridade: FALHOU!" << endl;
    }

    return estado;
}
