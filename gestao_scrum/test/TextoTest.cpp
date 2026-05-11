#include "TextoTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void TextoTest::setUp () {
    texto = new Texto();
    estado = SUCESSO;
}

void TextoTest::tearDown() {
    delete texto;
}

void TextoTest::testarCenarioSucesso() {
    try {
    texto->setTexto(TEXTO_VALIDO1);
    assert(texto->getTexto() == TEXTO_VALIDO1);

    texto->setTexto(TEXTO_VALIDO2);
    assert(texto->getTexto() == TEXTO_VALIDO2);

    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << " [ERRO] Cenário de sucesso falhou: " << e.what() << endl;
    }
}

void TextoTest::testarCenarioFalha() {
    try {
        texto->setTexto(TEXTO_INVALIDO1);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto inválido: maior do que 40 caracteres. " << endl;
    } catch (invalid_argument&) {}

    try {
        texto->setTexto(TEXTO_INVALIDO2);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto invalido: com espaço no início." << endl;
    } catch (invalid_argument&) {}

    try {
        texto->setTexto(TEXTO_INVALIDO3);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto inválido: com caracteres vedados." << endl;
    } catch (invalid_argument&) {}

    try {
        texto->setTexto(TEXTO_INVALIDO4);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto inválido: com ponto no final." << endl;
    } catch (invalid_argument&) {}

    try{
        texto->setTexto(TEXTO_INVALIDO5);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto inválido: com espaço antes da pontuação." << endl;
    } catch (invalid_argument&) {}
}

int TextoTest::run() {
    cout << "Rodando testes da classe Texto..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "Testes de Texto: OK!" << endl;
    } else {
        cout << "Testes de Texto: FALHA!" << endl;
    }
    return estado;
}
