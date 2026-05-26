#include <iostream>

// Testes de dominio
#include "CodigoTest.hpp"
#include "DataTest.hpp"
#include "EmailTest.hpp"
#include "EstadoTest.hpp"
#include "NomeTest.hpp"
#include "PapelTest.hpp"
#include "PrioridadeTest.hpp"
#include "SenhaTest.hpp"
#include "TempoTest.hpp"
#include "TextoTest.hpp"

// Testes de entidade
#include "HistoriaUsuarioTest.hpp"
#include "PessoaTest.hpp"
#include "PlanoSprintTest.hpp"
#include "ProjetoTest.hpp"

using namespace std;

int main() {
    cout << "=== INICIANDO SUITE DE TESTES ===" << endl << endl;

    bool todosSucesso = true;
    // run() retorna 0 (SUCESSO) quando todos os casos do teste passam.

    cout << "--- Dominios ---" << endl;
    CodigoTest codigoTest;          if (codigoTest.run() != 0) todosSucesso = false;
    DataTest dataTest;              if (dataTest.run() != 0) todosSucesso = false;
    EmailTest emailTest;            if (emailTest.run() != 0) todosSucesso = false;
    EstadoTest estadoTest;          if (estadoTest.run() != 0) todosSucesso = false;
    NomeTest nomeTest;              if (nomeTest.run() != 0) todosSucesso = false;
    PapelTest papelTest;            if (papelTest.run() != 0) todosSucesso = false;
    PrioridadeTest prioridadeTest;  if (prioridadeTest.run() != 0) todosSucesso = false;
    SenhaTest senhaTest;            if (senhaTest.run() != 0) todosSucesso = false;
    TempoTest tempoTest;            if (tempoTest.run() != 0) todosSucesso = false;
    TextoTest textoTest;            if (textoTest.run() != 0) todosSucesso = false;

    cout << endl << "--- Entidades ---" << endl;
    HistoriaUsuarioTest historiaTest; if (historiaTest.run() != 0) todosSucesso = false;
    PessoaTest pessoaTest;            if (pessoaTest.run() != 0) todosSucesso = false;
    PlanoSprintTest planoTest;        if (planoTest.run() != 0) todosSucesso = false;
    ProjetoTest projetoTest;          if (projetoTest.run() != 0) todosSucesso = false;

    cout << endl << "=== RESULTADO FINAL ===" << endl;

    if (todosSucesso) {
        cout << "Todos os testes passaram com sucesso!" << endl;
        return 0;
    } else {
        cout << "Existem testes falhando. Verifique o log." << endl;
        return 1;
    }
}
