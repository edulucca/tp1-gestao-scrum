#include "MSA_AuthServiceStubTest.hpp"
#include "MSC_CadastroServiceStub.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

void MSA_AuthServiceStubTest::setUp() {
    mscStub = new MSC_CadastroServiceStub();
    stub = new MSA_AuthServiceStub();
    stub->setCadastroService(mscStub);
    estado = SUCESSO;
}

void MSA_AuthServiceStubTest::tearDown() {
    delete stub;
    delete mscStub;
}

void MSA_AuthServiceStubTest::testarCenarioSucesso() {
    try {
        string nome;
        string papel;
        cout << "  [VALIDO] autenticar(luis.serra@unb.br, a1B2c3)" << endl;
        bool resultado = stub->autenticar(
            MSC_CadastroServiceStub::EMAIL_PADRAO,
            MSC_CadastroServiceStub::SENHA_PADRAO,
            nome,
            papel);
        if (!resultado || nome != "Luis Serra" || papel != "MESTRE SCRUM") {
            estado = FALHA;
            cout << "  [ERRO] Cenario de sucesso retornou dados incorretos." << endl;
        }
    } catch (runtime_error& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso lancou excecao: " << e.what() << endl;
    }
}

void MSA_AuthServiceStubTest::testarCenarioFalha() {
    try {
        string nome;
        string papel;
        cout << "  [INVALIDO] autenticar(67890@unb.br, a1B2c3)" << endl;
        bool resultado = stub->autenticar("67890@unb.br", MSC_CadastroServiceStub::SENHA_PADRAO, nome, papel);
        if (resultado) {
            estado = FALHA;
            cout << "  [ERRO] Cenario de falha retornou true." << endl;
        }
    } catch (runtime_error&) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de falha lancou excecao indevida." << endl;
    }
}

int MSA_AuthServiceStubTest::run() {
    cout << "Rodando testes do stub MSA_AuthServiceStub..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de MSA_AuthServiceStub: OK!" << endl;
    } else {
        cout << "-> Testes de MSA_AuthServiceStub: FALHOU!" << endl;
    }

    return estado;
}
