#pragma once
#include "Pessoa.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha da entidade Pessoa.
class PessoaTest {
    private:
        Pessoa* pessoa;
        int estado;

        const string EMAIL_VALIDO = "luis.serra@unb.br";
        const string NOME_VALIDO = "Luis Serra";
        const string SENHA_VALIDA = "a1B2c3";
        const string PAPEL_VALIDO = "MESTRE SCRUM";

        const string EMAIL_INVALIDO = ".luis.serra@unb.br";
        const string NOME_INVALIDO = " Luis Serra";
        const string SENHA_INVALIDA = "abc123";
        const string PAPEL_INVALIDO = "GERENTE";

        const string OUTRO_EMAIL_VALIDO = "maria@unb.br";

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
