#include "ProjetoTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void ProjetoTest::setUp() {
    projeto = new Projeto();
    estado = SUCESSO;
}

void ProjetoTest::tearDown() {
    delete projeto;
}

void ProjetoTest::testarCenarioSucesso() {
    try {
        projeto->setNome(NOME_VALIDO);
        assert(projeto->getNome() == NOME_VALIDO);

        projeto->setDataInicio(DATA_VALIDA);
        assert(projeto->getDataInicio() == DATA_VALIDA);

        projeto->setDataTermino(DATA_VALIDA);
        assert(projeto->getDataTermino() == DATA_VALIDA);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void ProjetoTest::testarCenarioFalha() {
    try {
        projeto->setNome(NOME_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou Nome invalido." << endl;
    } catch (invalid_argument& e) {

    }

    try {
        projeto->setDataInicio(DATA_INVALIDA);
        estado = FALHA;
        cout << "  [ERRO] Aceitou Data de Inicio invalida." << endl;
    } catch (invalid_argument& e) {

    }
}

int ProjetoTest::run() {
    cout << "Rodando testes da entidade Projeto..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Projeto: OK!" << endl;
    } else {
        cout << "-> Testes de Projeto: FALHOU!" << endl;
    }

    return estado;
}
