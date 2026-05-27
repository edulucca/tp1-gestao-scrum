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
    cout << "  [VALIDO] setTexto(" << TEXTO_VALIDO1 << ")" << endl;
    texto->setTexto(TEXTO_VALIDO1);
    assert(texto->getTexto() == TEXTO_VALIDO1);

    cout << "  [VALIDO] setTexto(" << TEXTO_VALIDO2 << ")" << endl;
    texto->setTexto(TEXTO_VALIDO2);
    assert(texto->getTexto() == TEXTO_VALIDO2);

    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << " [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void TextoTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setTexto(" << TEXTO_INVALIDO1 << ")" << endl;
        texto->setTexto(TEXTO_INVALIDO1);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto invalido: maior do que 40 caracteres. " << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setTexto(" << TEXTO_INVALIDO2 << ")" << endl;
        texto->setTexto(TEXTO_INVALIDO2);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto invalido: com espa�o no in�cio." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setTexto(" << TEXTO_INVALIDO3 << ")" << endl;
        texto->setTexto(TEXTO_INVALIDO3);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto invalido: com caracteres vedados." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setTexto(" << TEXTO_INVALIDO4 << ")" << endl;
        texto->setTexto(TEXTO_INVALIDO4);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto invalido: com ponto no final." << endl;
    } catch (invalid_argument&) {}

    try{
        cout << "  [INVALIDO] setTexto(" << TEXTO_INVALIDO5 << ")" << endl;
        texto->setTexto(TEXTO_INVALIDO5);
        estado = FALHA;
        cout << " [ERRO] Aceitou texto invalido: com espao antes da pontuacao." << endl;
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
