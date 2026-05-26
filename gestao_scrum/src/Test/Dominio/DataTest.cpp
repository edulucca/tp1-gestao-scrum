#include "DataTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void DataTest::setUp() {
    data = new Data();
    estado = SUCESSO;
}

void DataTest::tearDown() {
    delete data;
}

void DataTest::testarCenarioSucesso() {
    try {
        data->setData(DATA_VALIDA);
        assert(data->getData() == DATA_VALIDA);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void DataTest::testarCenarioFalha() {
    try {
        data->setData(DATA_INVALIDA1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou data invalida (dia/mes fora do intervalo)." << endl;
    } catch (invalid_argument&) {}

    try {
        data->setData(DATA_INVALIDA2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou data invalida (31 de abril)." << endl;
    } catch (invalid_argument&) {}

    try {
        data->setData(DATA_INVALIDA3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou data invalida (29/02 em ano nao bissexto)." << endl;
    } catch (invalid_argument&) {}

    try {
        data->setData(DATA_INVALIDA4);
        estado = FALHA;
        cout << "  [ERRO] Aceitou data invalida (formato sem barras)." << endl;
    } catch (invalid_argument&) {}
}

int DataTest::run() {
    cout << "Rodando testes do dominio Data..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Data: OK!" << endl;
    } else {
        cout << "-> Testes de Data: FALHOU!" << endl;
    }

    return estado;
}
