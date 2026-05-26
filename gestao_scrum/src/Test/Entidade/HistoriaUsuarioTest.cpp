#include "HistoriaUsuarioTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void HistoriaUsuarioTest::setUp() {
    historia = new HistoriaUsuario();
    estado = SUCESSO;
}

void HistoriaUsuarioTest::tearDown() {
    delete historia;
}

void HistoriaUsuarioTest::testarCenarioSucesso() {
    try {
        // Ao ser criada, a historia deve iniciar no estado "A FAZER".
        assert(historia->getEstado() == "A FAZER");

        historia->setCodigo(CODIGO_VALIDO);
        assert(historia->getCodigo() == CODIGO_VALIDO);

        historia->setTitulo(TITULO_VALIDO);
        assert(historia->getTitulo() == TITULO_VALIDO);

        historia->setPapel(PAPEL_VALIDO);
        assert(historia->getPapel() == PAPEL_VALIDO);

        historia->setAcao(ACAO_VALIDA);
        assert(historia->getAcao() == ACAO_VALIDA);

        historia->setValor(VALOR_VALIDO);
        assert(historia->getValor() == VALOR_VALIDO);

        historia->setEstimativa(ESTIMATIVA_VALIDA);
        assert(historia->getEstimativa() == ESTIMATIVA_VALIDA);

        historia->setPrioridade(PRIORIDADE_VALIDA);
        assert(historia->getPrioridade() == PRIORIDADE_VALIDA);

        historia->setEstado(ESTADO_VALIDO);
        assert(historia->getEstado() == ESTADO_VALIDO);
    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso falhou: " << e.what() << endl;
    }
}

void HistoriaUsuarioTest::testarCenarioFalha() {
    try {
        historia->setCodigo(CODIGO_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou codigo invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setTitulo(TITULO_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou titulo invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setPapel(PAPEL_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou papel invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setAcao(ACAO_INVALIDA);
        estado = FALHA;
        cout << "  [ERRO] Aceitou acao invalida." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setValor(VALOR_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou valor invalido." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setEstimativa(ESTIMATIVA_INVALIDA);
        estado = FALHA;
        cout << "  [ERRO] Aceitou estimativa invalida." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setPrioridade(PRIORIDADE_INVALIDA);
        estado = FALHA;
        cout << "  [ERRO] Aceitou prioridade invalida." << endl;
    } catch (invalid_argument&) {}

    try {
        historia->setEstado(ESTADO_INVALIDO);
        estado = FALHA;
        cout << "  [ERRO] Aceitou estado invalido." << endl;
    } catch (invalid_argument&) {}

    // Chave primaria (codigo) nao pode ser editada apos definida.
    try {
        historia->setCodigo(CODIGO_VALIDO);
        historia->setCodigo(OUTRO_CODIGO_VALIDO);
        estado = FALHA;
        cout << "  [ERRO] Permitiu editar a chave primaria (codigo)." << endl;
    } catch (invalid_argument&) {}
}

int HistoriaUsuarioTest::run() {
    cout << "Rodando testes da entidade HistoriaUsuario..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de HistoriaUsuario: OK!" << endl;
    } else {
        cout << "-> Testes de HistoriaUsuario: FALHOU!" << endl;
    }

    return estado;
}
