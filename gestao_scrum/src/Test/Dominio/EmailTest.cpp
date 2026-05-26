#include "EmailTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void EmailTest::setUp() {
    email = new Email();
    estado = SUCESSO;
}

void EmailTest::tearDown() {
    delete email;
}

void EmailTest::testarCenarioSucesso() {
    try {
        email->setEmail(EMAIL_VALIDO);
        assert(email->getEmail() == EMAIL_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void EmailTest::testarCenarioFalha() {
    try {
        email->setEmail(EMAIL_INVALIDO1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou email invalido (inicia com ponto)." << endl;
    } catch (invalid_argument&) {}

    try {
        email->setEmail(EMAIL_INVALIDO2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou email invalido (sem arroba)." << endl;
    } catch (invalid_argument&) {}

    try {
        email->setEmail(EMAIL_INVALIDO3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou email invalido (sem parte local)." << endl;
    } catch (invalid_argument&) {}

    try {
        email->setEmail(EMAIL_INVALIDO4);
        estado = FALHA;
        cout << "  [ERRO] Aceitou email invalido (parte do dominio termina em hifen)." << endl;
    } catch (invalid_argument&) {}
}

int EmailTest::run() {
    cout << "Rodando testes do dominio Email..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Email: OK!" << endl;
    } else {
        cout << "-> Testes de Email: FALHOU!" << endl;
    }

    return estado;
}
