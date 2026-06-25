#pragma once

#include "MAA_Commands.hpp"
#include "MAC_Commands.hpp"
#include "MAG_Commands.hpp"
#include "MSA_AuthServiceStub.hpp"
#include "MSC_CadastroServiceStub.hpp"
#include "MSG_GestaoServiceStub.hpp"

using namespace std;

/// Testa execucao dos comandos concretos de apresentacao.
class CommandTest {
private:
    int estado;

    void testarLoginCommand();
    void testarLogoutCommand();
    void testarCriarPessoaCommand();
    void testarListarPessoasCommand();
    void testarListarHistoriasCommand();
    void testarAtualizarHistoriaCommand();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};
