#include "MAG_Commands.hpp"

ListarHistoriasCommand::ListarHistoriasCommand(
    IMSG_GestaoService* gestaoService,
    const string& codigoProjeto,
    vector<HistoriaUsuario*>* historias)
    : gestaoService(gestaoService), codigoProjeto(codigoProjeto), historias(historias) {}

void ListarHistoriasCommand::execute() {
    if (gestaoService != nullptr && historias != nullptr) {
        *historias = gestaoService->listarHistoriasPorProjeto(codigoProjeto);
    }
}
