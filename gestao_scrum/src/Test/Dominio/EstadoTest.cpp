#include "EstadoTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void EstadoTest::setUp() {
    estadoObj = new Estado();
    estado = SUCESSO;
}

void EstadoTest::tearDown() {
    delete estadoObj;
}

void EstadoTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setEstado(" << ESTADO_VALIDO << ")" << endl;
        estadoObj->setEstado(ESTADO_VALIDO);
        assert(estadoObj->getEstado() == ESTADO_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void EstadoTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setEstado(" << ESTADO_INVALIDO1 << ")" << endl;
        estadoObj->setEstado(ESTADO_INVALIDO1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou estado invalido (valor inexistente)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setEstado(" << ESTADO_INVALIDO2 << ")" << endl;
        estadoObj->setEstado(ESTADO_INVALIDO2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou estado invalido (caixa incorreta)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setEstado(" << ESTADO_INVALIDO3 << ")" << endl;
        estadoObj->setEstado(ESTADO_INVALIDO3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou estado invalido (vazio)." << endl;
    } catch (invalid_argument&) {}
}

int EstadoTest::run() {
    cout << "Rodando testes do dominio Estado..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Estado: OK!" << endl;
    } else {
        cout << "-> Testes de Estado: FALHOU!" << endl;
    }

    return estado;
}
