#include "TempoTest.hpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

void TempoTest::setUp() {
    tempo = new Tempo();
    estado = SUCESSO;
}

void TempoTest::tearDown() {
    delete tempo;
}

void TempoTest::testarCenarioSucesso() {
    try {
        tempo->setTempo(TEMPO_VALIDO1);
        assert(tempo->getTempo() == TEMPO_VALIDO1);

        tempo->setTempo(TEMPO_VALIDO2);
        assert(tempo->getTempo() == TEMPO_VALIDO2);

        tempo->setTempo(TEMPO_VALIDO3);
        assert(tempo->getTempo() == TEMPO_VALIDO3);

    } catch (invalid_argument& e) {
        estado = FALHA;
        cout << " [ERRO] Cenário de sucesso falhou: " << e.what() << endl;
    }
}

void TempoTest::testarCenarioFalha() {
    try {
        tempo->setTempo(TEMPO_INVALIDO1);
        estado = FALHA;
        cout << " [ERRO] Aceitou tempo inválido (0 dias)." << endl;
    } catch (invalid_argument&) {}

    try {
        tempo->setTempo(TEMPO_INVALIDO2);
        estado = FALHA;
        cout << " [ERRO] Aceitou tempo inválido (366 dias), superior ao permitido." << endl;
    } catch (invalid_argument&) {}

    try {
        tempo->setTempo(TEMPO_INVALIDO3);
        estado = FALHA;
        cout << " [ERRO] Aceitou tempo inválido (- 10 dias): negativo e inferior ao permitido." << endl;
    } catch (invalid_argument&) {}
}

    int TempoTest::run() {
        cout << "Rodando testes da classe Tempo..." << endl;

        setUp();
        testarCenarioSucesso();
        tearDown();

        setUp();
        testarCenarioFalha();
        tearDown();

        if (estado == SUCESSO) {
            cout << "Testes de Tempo: OK!" << endl;
        } else {
            cout << "Testes de Tempo: FALHA!" << endl;
        }
    return estado;
    }
