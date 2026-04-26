#include <iostream>
#include "ProjetoTest.hpp"

using namespace std;

int main() {
    cout << "=== INICIANDO SUITE DE TESTES ===" << endl << endl;

    ProjetoTest projetoTest;
    int resultadoProjeto = projetoTest.run();

    cout << endl << "=== RESULTADO FINAL ===" << endl;
    if (resultadoProjeto == ProjetoTest::SUCESSO) {
        cout << "Todos os testes passaram com sucesso!" << endl;
        return 0;
    } else {
        cout << "Existem testes falhando. Verifique o log." << endl;
        return 1;
    }
}
