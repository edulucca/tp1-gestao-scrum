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
        cout << "  [VALIDO] setNome(" << NOME_VALIDO << ")" << endl;
        projeto->setNome(NOME_VALIDO);
        assert(projeto->getNome() == NOME_VALIDO);

        cout << "  [VALIDO] setDataInicio(" << DATA_VALIDA << ")" << endl;
        projeto->setDataInicio(DATA_VALIDA);
        assert(projeto->getDataInicio() == DATA_VALIDA);

        cout << "  [VALIDO] setDataTermino(" << DATA_VALIDA_FIM << ")" << endl;
        projeto->setDataTermino(DATA_VALIDA_FIM);
        assert(projeto->getDataTermino() == DATA_VALIDA_FIM);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void ProjetoTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setNome(" << NOME_INVALIDO << ")" << endl;
        projeto->setNome(NOME_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou Nome invalido." << endl;
    } catch (invalid_argument& e) {

    }

    try {
        cout << "  [INVALIDO] setDataInicio(" << DATA_INVALIDA << ")" << endl;
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
