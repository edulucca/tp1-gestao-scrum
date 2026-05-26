#include "CodigoTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void CodigoTest::setUp() {
    codigo = new Codigo();
    estado = SUCESSO;
}

void CodigoTest::tearDown() {
    delete codigo;
}

void CodigoTest::testarCenarioSucesso() {
    try {
        codigo->setCodigo(CODIGO_VALIDO);
        assert(codigo->getCodigo() == CODIGO_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void CodigoTest::testarCenarioFalha() {
    try {
        codigo->setCodigo(CODIGO_INVALIDO1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou codigo invalido (letras minusculas)." << endl;
    } catch (invalid_argument&) {}

    try {
        codigo->setCodigo(CODIGO_INVALIDO2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou codigo invalido (apenas uma letra)." << endl;
    } catch (invalid_argument&) {}

    try {
        codigo->setCodigo(CODIGO_INVALIDO3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou codigo invalido (menos de 5 caracteres)." << endl;
    } catch (invalid_argument&) {}

    try {
        codigo->setCodigo(CODIGO_INVALIDO4);
        estado = FALHA;
        cout << "  [ERRO] Aceitou codigo invalido (mais de 5 caracteres)." << endl;
    } catch (invalid_argument&) {}
}

int CodigoTest::run() {
    cout << "Rodando testes do dominio Codigo..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Codigo: OK!" << endl;
    } else {
        cout << "-> Testes de Codigo: FALHOU!" << endl;
    }

    return estado;
}
