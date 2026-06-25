#include "CommandTest.hpp"
#include "MSC_CadastroServiceStub.hpp"

#include <iostream>
#include <memory>

using namespace std;

void CommandTest::testarLoginCommand() {
    MSC_CadastroServiceStub mscStub;
    MSA_AuthServiceStub msaStub;
    msaStub.setCadastroService(&mscStub);
    bool resultado = false;
    string nome;
    string papel;

    cout << "  [VALIDO] LoginCommand::execute()" << endl;
    LoginCommand command(
        &msaStub,
        MSC_CadastroServiceStub::EMAIL_PADRAO,
        MSC_CadastroServiceStub::SENHA_PADRAO,
        &resultado,
        &nome,
        &papel);
    command.execute();

    if (!resultado || nome != "Luis Serra") {
        estado = FALHA;
        cout << "  [ERRO] LoginCommand nao autenticou credenciais validas." << endl;
    }
}

void CommandTest::testarLogoutCommand() {
    cout << "  [VALIDO] LogoutCommand::execute()" << endl;
    LogoutCommand command;
    command.execute();
}

void CommandTest::testarCriarPessoaCommand() {
    MSC_CadastroServiceStub stub;
    Pessoa pessoa;
    pessoa.setEmail("joao.silva@unb.br");
    pessoa.setNome("Joao Silva");
    pessoa.setSenha("a1B2c3");
    pessoa.setPapel("MESTRE SCRUM");
    bool resultado = false;

    cout << "  [VALIDO] CriarPessoaCommand::execute()" << endl;
    CriarPessoaCommand command(&stub, &pessoa, &resultado);
    command.execute();

    if (!resultado) {
        estado = FALHA;
        cout << "  [ERRO] CriarPessoaCommand nao cadastrou pessoa valida." << endl;
    }
}

void CommandTest::testarListarHistoriasCommand() {
    MSG_GestaoServiceStub stub;
    vector<HistoriaUsuario*> historias;

    cout << "  [VALIDO] ListarHistoriasCommand::execute()" << endl;
    ListarHistoriasCommand command(&stub, "AB123", &historias);
    command.execute();

    if (historias.empty()) {
        estado = FALHA;
        cout << "  [ERRO] ListarHistoriasCommand retornou lista vazia." << endl;
    }
}

void CommandTest::testarAtualizarHistoriaCommand() {
    MSG_GestaoServiceStub stub;
    bool resultado = false;

    cout << "  [VALIDO] AtualizarHistoriaCommand::execute()" << endl;
    AtualizarHistoriaCommand command(&stub, "HU001", "FEITO", &resultado);
    command.execute();

    if (!resultado) {
        estado = FALHA;
        cout << "  [ERRO] AtualizarHistoriaCommand nao atualizou historia valida." << endl;
    }
}

int CommandTest::run() {
    cout << "Rodando testes dos comandos concretos..." << endl;
    estado = SUCESSO;

    testarLoginCommand();
    testarLogoutCommand();
    testarCriarPessoaCommand();
    testarListarHistoriasCommand();
    testarAtualizarHistoriaCommand();

    if (estado == SUCESSO) {
        cout << "-> Testes de Command: OK!" << endl;
    } else {
        cout << "-> Testes de Command: FALHOU!" << endl;
    }

    return estado;
}
