#include "PapelTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void PapelTest::setUp() {
    papel = new Papel();
    estado = SUCESSO;
}

void PapelTest::tearDown() {
    delete papel;
}

void PapelTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setPapel(" << PAPEL_VALIDO << ")" << endl;
        papel->setPapel(PAPEL_VALIDO);
        assert(papel->getPapel() == PAPEL_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void PapelTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setPapel(" << PAPEL_INVALIDO1 << ")" << endl;
        papel->setPapel(PAPEL_INVALIDO1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou papel invalido (inexistente)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setPapel(" << PAPEL_INVALIDO2 << ")" << endl;
        papel->setPapel(PAPEL_INVALIDO2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou papel invalido (caixa incorreta)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setPapel(" << PAPEL_INVALIDO3 << ")" << endl;
        papel->setPapel(PAPEL_INVALIDO3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou papel invalido (vazio)." << endl;
    } catch (invalid_argument&) {}
}

int PapelTest::run() {
    cout << "Rodando testes do dominio Papel..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Papel: OK!" << endl;
    } else {
        cout << "-> Testes de Papel: FALHOU!" << endl;
    }

    return estado;
}
