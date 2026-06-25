#include "MAC_Commands.hpp"

ListarPessoasCommand::ListarPessoasCommand(
    IMSC_CadastroService* cadastroService,
    vector<PessoaResumo>* pessoas)
    : cadastroService(cadastroService), pessoas(pessoas) {}

void ListarPessoasCommand::execute() {
    if (cadastroService != nullptr && pessoas != nullptr) {
        *pessoas = cadastroService->listarPessoas();
    }
}
