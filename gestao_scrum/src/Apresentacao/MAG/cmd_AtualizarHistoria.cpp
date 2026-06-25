#include "MAG_Commands.hpp"

AtualizarHistoriaCommand::AtualizarHistoriaCommand(
    IMSG_GestaoService* gestaoService,
    const string& codigoHistoria,
    const string& estado,
    bool* resultado)
    : gestaoService(gestaoService),
      codigoHistoria(codigoHistoria),
      estado(estado),
      resultado(resultado) {}

void AtualizarHistoriaCommand::execute() {
    if (gestaoService != nullptr && resultado != nullptr) {
        *resultado = gestaoService->alterarEstadoHistoria(codigoHistoria, estado);
    }
}
