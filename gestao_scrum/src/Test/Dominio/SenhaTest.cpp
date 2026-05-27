#include "SenhaTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void SenhaTest::setUp() {
    senha = new Senha();
    estado = SUCESSO;
}

void SenhaTest::tearDown() {
    delete senha;
}

void SenhaTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setSenha(" << SENHA_VALIDA << ")" << endl;
        senha->setSenha(SENHA_VALIDA);
        assert(senha->getSenha() == SENHA_VALIDA);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void SenhaTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setSenha(" << SENHA_INVALIDA1 << ")" << endl;
        senha->setSenha(SENHA_INVALIDA1);
        estado = FALHA;
        cout << "  [ERRO] Aceitou senha invalida (letras consecutivas)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setSenha(" << SENHA_INVALIDA2 << ")" << endl;
        senha->setSenha(SENHA_INVALIDA2);
        estado = FALHA;
        cout << "  [ERRO] Aceitou senha invalida (sem letra maiuscula)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setSenha(" << SENHA_INVALIDA3 << ")" << endl;
        senha->setSenha(SENHA_INVALIDA3);
        estado = FALHA;
        cout << "  [ERRO] Aceitou senha invalida (sem letra minuscula)." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setSenha(" << SENHA_INVALIDA4 << ")" << endl;
        senha->setSenha(SENHA_INVALIDA4);
        estado = FALHA;
        cout << "  [ERRO] Aceitou senha invalida (menos de 6 caracteres)." << endl;
    } catch (invalid_argument&) {}
}

int SenhaTest::run() {
    cout << "Rodando testes do dominio Senha..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Senha: OK!" << endl;
    } else {
        cout << "-> Testes de Senha: FALHOU!" << endl;
    }

    return estado;
}
