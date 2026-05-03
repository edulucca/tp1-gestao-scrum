#include <iostream>
#include "TempoTest.hpp"
#include "TextoTest.hpp"
#include "ProjetoTest.hpp"

using namespace std;

int main() {
    cout << "=== INICIANDO SUITE DE TESTES ===" << endl << endl;

    TempoTest tempoTest;
    int resultadoTempo = tempoTest.run();

    TextoTest textoTest;
    int resultadoTexto = textoTest.run();

    ProjetoTest projetoTest;
    int resultadoProjeto = projetoTest.run();

    cout << endl << "=== RESULTADO FINAL ===" << endl;

    bool todosSucesso = true;
    if (resultadoTempo != TempoTest::SUCESSO) todosSucesso = false;
    if (resultadoTexto != TextoTest::SUCESSO) todosSucesso = false;
    if (resultadoProjeto != ProjetoTest::SUCESSO) todosSucesso = false;

    if (todosSucesso) {
        cout << "Todos os testes passaram com sucesso!" << endl;
        return 0;
    } else {
        cout << "Existem testes falhando. Verifique o log." << endl;
        return 1;
    }
}
