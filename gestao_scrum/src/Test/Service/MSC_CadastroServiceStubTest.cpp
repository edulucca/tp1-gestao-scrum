#include "MSC_CadastroServiceStubTest.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

void MSC_CadastroServiceStubTest::setUp() {
    stub = new MSC_CadastroServiceStub();
    estado = SUCESSO;
}

void MSC_CadastroServiceStubTest::tearDown() {
    delete stub;
}

Pessoa criarPessoaValida(const string& email) {
    Pessoa pessoa;
    pessoa.setEmail(email);
    pessoa.setNome("Joao Silva");
    pessoa.setSenha("a1B2c3");
    pessoa.setPapel("DESENVOLVEDOR");
    return pessoa;
}

void MSC_CadastroServiceStubTest::testarCenarioSucesso() {
    try {
        Pessoa pessoa = criarPessoaValida("joao.silva@unb.br");
        cout << "  [VALIDO] criarPessoa(joao.silva@unb.br)" << endl;
        bool resultado = stub->criarPessoa(pessoa);
        if (!resultado) {
            estado = FALHA;
            cout << "  [ERRO] Cenario de sucesso retornou false." << endl;
        }
    } catch (runtime_error& e) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de sucesso lancou excecao: " << e.what() << endl;
    }
}

void MSC_CadastroServiceStubTest::testarCenarioFalha() {
    try {
        Pessoa pessoa = criarPessoaValida("67890@unb.br");
        cout << "  [INVALIDO] criarPessoa(67890@unb.br)" << endl;
        bool resultado = stub->criarPessoa(pessoa);
        if (resultado) {
            estado = FALHA;
            cout << "  [ERRO] Cenario de falha retornou true." << endl;
        }
    } catch (runtime_error&) {
        estado = FALHA;
        cout << "  [ERRO] Cenario de falha lancou excecao indevida." << endl;
    }
}

void MSC_CadastroServiceStubTest::testarListarPessoasSucesso() {
    try {
        cout << "  [VALIDO] listarPessoas()" << endl;
        vector<PessoaResumo> pessoas = stub->listarPessoas();
        if (pessoas.empty()) {
            estado = FALHA;
            cout << "  [ERRO] listarPessoas retornou lista vazia." << endl;
        }
    } catch (runtime_error& e) {
        estado = FALHA;
        cout << "  [ERRO] listarPessoas lancou excecao: " << e.what() << endl;
    }
}

void MSC_CadastroServiceStubTest::testarListarPessoasAposCadastro() {
    try {
        Pessoa pessoa = criarPessoaValida("ana.silva@unb.br");
        stub->criarPessoa(pessoa);
        vector<PessoaResumo> pessoas = stub->listarPessoas();
        if (pessoas.size() < 2) {
            estado = FALHA;
            cout << "  [ERRO] listarPessoas nao incluiu novo cadastro." << endl;
        }
    } catch (runtime_error& e) {
        estado = FALHA;
        cout << "  [ERRO] listarPessoas apos cadastro lancou excecao: " << e.what() << endl;
    }
}

int MSC_CadastroServiceStubTest::run() {
    cout << "Rodando testes do stub MSC_CadastroServiceStub..." << endl;

    setUp();
    testarCenarioSucesso();
    tearDown();

    setUp();
    testarCenarioFalha();
    tearDown();

    setUp();
    testarListarPessoasSucesso();
    tearDown();

    setUp();
    testarListarPessoasAposCadastro();
    tearDown();

    if (estado == SUCESSO) {
        cout << "-> Testes de MSC_CadastroServiceStub: OK!" << endl;
    } else {
        cout << "-> Testes de MSC_CadastroServiceStub: FALHOU!" << endl;
    }

    return estado;
}
