#include "PessoaTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void PessoaTest::setUp() {
    pessoa = new Pessoa();
    estado = SUCESSO;
}

void PessoaTest::tearDown() {
    delete pessoa;
}

void PessoaTest::testarCenarioSucesso() {
    try {
        cout << "  [VALIDO] setEmail(" << EMAIL_VALIDO << ")" << endl;
        pessoa->setEmail(EMAIL_VALIDO);
        assert(pessoa->getEmail() == EMAIL_VALIDO);

        cout << "  [VALIDO] setNome(" << NOME_VALIDO << ")" << endl;
        pessoa->setNome(NOME_VALIDO);
        assert(pessoa->getNome() == NOME_VALIDO);

        cout << "  [VALIDO] setSenha(" << SENHA_VALIDA << ")" << endl;
        pessoa->setSenha(SENHA_VALIDA);
        assert(pessoa->getSenha() == SENHA_VALIDA);

        cout << "  [VALIDO] setPapel(" << PAPEL_VALIDO << ")" << endl;
        pessoa->setPapel(PAPEL_VALIDO);
        assert(pessoa->getPapel() == PAPEL_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void PessoaTest::testarCenarioFalha() {
    try {
        cout << "  [INVALIDO] setEmail(" << EMAIL_INVALIDO << ")" << endl;
        pessoa->setEmail(EMAIL_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou email invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setNome(" << NOME_INVALIDO << ")" << endl;
        pessoa->setNome(NOME_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou nome invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setSenha(" << SENHA_INVALIDA << ")" << endl;
        pessoa->setSenha(SENHA_INVALIDA);
        estado = FALHA;
        cout << "  [ERRO] Aceitou senha invalida." << endl;
    } catch (invalid_argument&) {}

    try {
        cout << "  [INVALIDO] setPapel(" << PAPEL_INVALIDO << ")" << endl;
        pessoa->setPapel(PAPEL_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou papel invalido." << endl;
    } catch (invalid_argument&) {}

    // Chave primaria (email) nao pode ser editada apos definida.
    try {
        cout << "  [INVALIDO] setEmail(" << EMAIL_VALIDO << ") + setEmail(" << OUTRO_EMAIL_VALIDO << ")" << endl;
        pessoa->setEmail(EMAIL_VALIDO);
        pessoa->setEmail(OUTRO_EMAIL_VALIDO);
        estado = FALHA;
        cout << "  [ERRO] Permitiu editar a chave primaria (email)." << endl;
    } catch (invalid_argument&) {}
}

int PessoaTest::run() {
    cout << "Rodando testes da entidade Pessoa..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de Pessoa: OK!" << endl;
    } else {
        cout << "-> Testes de Pessoa: FALHOU!" << endl;
    }

    return estado;
}
