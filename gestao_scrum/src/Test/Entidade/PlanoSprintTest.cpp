#include "PlanoSprintTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void PlanoSprintTest::setUp() {
    plano = new PlanoSprint();
    estado = SUCESSO;
}

void PlanoSprintTest::tearDown() {
    delete plano;
}

void PlanoSprintTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setCodigo(" << CODIGO_VALIDO << ")" << endl;
        plano->setCodigo(CODIGO_VALIDO);
        assert(plano->getCodigo() == CODIGO_VALIDO);

        cout << "  [VALIDO] setObjetivo(" << OBJETIVO_VALIDO << ")" << endl;
        plano->setObjetivo(OBJETIVO_VALIDO);
        assert(plano->getObjetivo() == OBJETIVO_VALIDO);

        cout << "  [VALIDO] setCapacidade(" << CAPACIDADE_VALIDA << ")" << endl;
        plano->setCapacidade(CAPACIDADE_VALIDA);
        assert(plano->getCapacidade() == CAPACIDADE_VALIDA);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void PlanoSprintTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setCodigo(" << CODIGO_INVALIDO << ")" << endl;
        plano->setCodigo(CODIGO_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou codigo invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setObjetivo(" << OBJETIVO_INVALIDO << ")" << endl;
        plano->setObjetivo(OBJETIVO_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou objetivo invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setCapacidade(" << CAPACIDADE_INVALIDA << ")" << endl;
        plano->setCapacidade(CAPACIDADE_INVALIDA);
        estado = FALHA;
        cout << "  [ERRO] Aceitou capacidade invalida." << endl;
    } catch (invalid_argument&) {}

    // Chave primaria (codigo) nao pode ser editada apos definida.
    try {
        cout << "  [INVALIDO] setCodigo(" << CODIGO_VALIDO << ") + setCodigo(" << OUTRO_CODIGO_VALIDO << ")" << endl;
        plano->setCodigo(CODIGO_VALIDO);
        plano->setCodigo(OUTRO_CODIGO_VALIDO);
        estado = FALHA;
        cout << "  [ERRO] Permitiu editar a chave primaria (codigo)." << endl;
    } catch (invalid_argument&) {}
}

int PlanoSprintTest::run() {
    cout << "Rodando testes da entidade PlanoSprint..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de PlanoSprint: OK!" << endl;
    } else {
        cout << "-> Testes de PlanoSprint: FALHOU!" << endl;
    }

    return estado;
}
