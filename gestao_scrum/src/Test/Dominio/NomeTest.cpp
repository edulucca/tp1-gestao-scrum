#include "NomeTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void NomeTest::setUp() {
    nome = new Nome();
    estado = SUCESSO;
}

void NomeTest::tearDown() {
    delete nome;
}

void NomeTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setNome(" << NOME_VALIDO << ")" << endl;
        nome->setNome(NOME_VALIDO);
        assert(nome->getNome() == NOME_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void NomeTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setNome(" << NOME_INVALIDO1 << ")" << endl;
        nome->setNome(NOME_INVALIDO1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou nome invalido (inicia com espaco)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setNome(" << NOME_INVALIDO2 << ")" << endl;
        nome->setNome(NOME_INVALIDO2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou nome invalido (termina com espaco)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setNome(" << NOME_INVALIDO3 << ")" << endl;
        nome->setNome(NOME_INVALIDO3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou nome invalido (mais de 10 caracteres)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setNome(" << NOME_INVALIDO4 << ")" << endl;
        nome->setNome(NOME_INVALIDO4);
        estado = FALHA;
        cout << "  [ERRO] Aceitou nome invalido (contem digitos)." << endl;
    } catch (invalid_argument&) {}
}

int NomeTest::run() {
    cout << "Rodando testes do dominio Nome..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Nome: OK!" << endl;
    } else {
        cout << "-> Testes de Nome: FALHOU!" << endl;
    }

    return estado;
}
