#include "MAC_Commands.hpp"

CriarPessoaCommand::CriarPessoaCommand(IMSC_CadastroService* cadastroService, Pessoa* pessoa, bool* resultado)
    : cadastroService(cadastroService), pessoa(pessoa), resultado(resultado) {}

void CriarPessoaCommand::execute() {
    if (cadastroService != nullptr && pessoa != nullptr && resultado != nullptr) {
        *resultado = cadastroService->criarPessoa(*pessoa);
    }
}
