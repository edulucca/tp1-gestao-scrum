#pragma once

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @class EntradaCancelada
 * @ingroup aplicacao
 * @brief Excecao lancada quando o usuario cancela uma entrada (digita 0).
 */
class EntradaCancelada : public runtime_error {
public:
    /** @brief Constroi a excecao com mensagem padrao de cancelamento. */
    EntradaCancelada() : runtime_error("Entrada cancelada.") {}
};

/**
 * @namespace EntradaUsuario
 * @ingroup aplicacao
 * @brief Funcoes utilitarias para leitura e validacao basica de entrada do usuario.
 */
namespace EntradaUsuario {

/** @brief Descarta caracteres restantes no buffer de entrada padrao. */
inline void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Remove caractere de retorno de carro do final da string, se presente.
 * @param entrada String a normalizar.
 */
inline void removerRetornoCarro(string& entrada) {
    if (!entrada.empty() && entrada.back() == '\r') {
        entrada.pop_back();
    }
}

/**
 * @brief Verifica se a entrada padrao esta em estado valido; limpa e lanca excecao se nao.
 * @throw EntradaCancelada Se o fluxo de entrada estiver corrompido.
 */
inline void verificarInterrupcao() {
    if (!cin.good()) {
        cin.clear();
        limparBuffer();
        throw EntradaCancelada();
    }
}

/**
 * @brief Verifica se a entrada representa cancelamento (valor "0").
 * @param entrada Valor lido do usuario.
 * @return true se for cancelamento; false caso contrario.
 */
inline bool ehCancelamento(const string& entrada) {
    return entrada == "0";
}

/**
 * @brief Le uma palavra (sem espacos) do usuario.
 * @param rotulo Texto exibido antes do prompt.
 * @param permitirCancelar Se true, aceita "0" como cancelamento.
 * @return Palavra informada pelo usuario.
 * @throw EntradaCancelada Se o usuario cancelar ou a entrada for interrompida.
 */
inline string lerPalavra(const string& rotulo, bool permitirCancelar) {
    string entrada;
    while (true) {
        cout << rotulo;
        if (permitirCancelar) {
            cout << " (0 para cancelar)";
        }
        cout << ": ";
        cin >> entrada;
        verificarInterrupcao();
        if (permitirCancelar && ehCancelamento(entrada)) {
            throw EntradaCancelada();
        }
        return entrada;
    }
}

/**
 * @brief Le uma linha completa (com espacos) do usuario.
 * @param rotulo Texto exibido antes do prompt.
 * @param limparBufferAntes Se true, descarta o buffer antes de ler.
 * @param permitirCancelar Se true, aceita "0" como cancelamento.
 * @return Linha informada pelo usuario.
 * @throw EntradaCancelada Se o usuario cancelar ou a entrada for interrompida.
 */
inline string lerLinha(const string& rotulo, bool limparBufferAntes, bool permitirCancelar) {
    if (limparBufferAntes) {
        limparBuffer();
    }
    string entrada;
    while (true) {
        cout << rotulo;
        if (permitirCancelar) {
            cout << " (0 para cancelar)";
        }
        cout << ": ";
        getline(cin, entrada);
        verificarInterrupcao();
        removerRetornoCarro(entrada);
        if (permitirCancelar && ehCancelamento(entrada)) {
            throw EntradaCancelada();
        }
        return entrada;
    }
}

/**
 * @brief Le um numero inteiro do usuario com revalidacao em caso de formato invalido.
 * @param rotulo Texto exibido antes do prompt.
 * @param limparBufferAntes Se true, descarta o buffer antes de ler.
 * @param permitirCancelar Se true, aceita "0" como cancelamento.
 * @return Inteiro informado pelo usuario.
 * @throw EntradaCancelada Se o usuario cancelar ou a entrada for interrompida.
 */
inline int lerInteiro(const string& rotulo, bool limparBufferAntes, bool permitirCancelar) {
    if (limparBufferAntes) {
        limparBuffer();
    }
    while (true) {
        cout << rotulo;
        if (permitirCancelar) {
            cout << " (0 para cancelar)";
        }
        cout << ": ";
        string entrada;
        getline(cin, entrada);
        verificarInterrupcao();
        removerRetornoCarro(entrada);
        if (permitirCancelar && ehCancelamento(entrada)) {
            throw EntradaCancelada();
        }
        try {
            return stoi(entrada);
        } catch (...) {
            cout << endl << "Valor numerico invalido." << endl;
        }
    }
}

} // namespace EntradaUsuario
