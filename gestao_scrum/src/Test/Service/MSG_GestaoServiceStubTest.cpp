#include "MSG_GestaoServiceStubTest.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

void MSG_GestaoServiceStubTest::setUp() {
    stub = new MSG_GestaoServiceStub();
    estado = SUCESSO;
}

void MSG_GestaoServiceStubTest::tearDown() {
    delete stub;
}

void MSG_GestaoServiceStubTest::testarListarHistoriasPorProjeto() {
    try {
        cout << "  [VALIDO] listarHistoriasPorProjeto(AB123)" << endl;
        vector<HistoriaUsuario*> historias = stub->listarHistoriasPorProjeto("AB123");
        if (historias.empty()) {
            estado = FALHA;
            cout << "  [ERRO] listarHistoriasPorProjeto retornou lista vazia." << endl;
        }
    } catch (runtime_error& e) {
        estado = FALHA;
        cout << "  [ERRO] listarHistoriasPorProjeto lancou excecao: " << e.what() << endl;
    }
}

void MSG_GestaoServiceStubTest::testarAlterarEstadoHistoria() {
    try {
        cout << "  [VALIDO] alterarEstadoHistoria(HU001, FAZENDO)" << endl;
        bool resultado = stub->alterarEstadoHistoria("HU001", "FAZENDO");
        if (!resultado) {
            estado = FALHA;
            cout << "  [ERRO] alterarEstadoHistoria retornou false." << endl;
        }
    } catch (runtime_error& e) {
        estado = FALHA;
        cout << "  [ERRO] alterarEstadoHistoria lancou excecao: " << e.what() << endl;
    }
}

int MSG_GestaoServiceStubTest::run() {
    cout << "Rodando testes do stub MSG_GestaoServiceStub..." << endl;

    setUp();
    testarListarHistoriasPorProjeto();
    tearDown();

    setUp();
    testarAlterarEstadoHistoria();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de MSG_GestaoServiceStub: OK!" << endl;
    } else {
        cout << "-> Testes de MSG_GestaoServiceStub: FALHOU!" << endl;
    }

    return estado;
}
