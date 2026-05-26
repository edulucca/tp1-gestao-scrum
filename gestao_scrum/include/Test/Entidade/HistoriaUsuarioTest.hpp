#pragma once
#include "HistoriaUsuario.hpp"

using namespace std;

/// Testa cenarios de sucesso e falha da entidade HistoriaUsuario.
class HistoriaUsuarioTest {
    private:
        HistoriaUsuario* historia;
        int estado;

        const string CODIGO_VALIDO = "HU123";
        const string TITULO_VALIDO = "Criar conta de usuario";
        const string PAPEL_VALIDO = "Desenvolvedor";
        const string ACAO_VALIDA = "cadastrar uma conta";
        const string VALOR_VALIDO = "acessar os servicos";
        const int ESTIMATIVA_VALIDA = 5;
        const string PRIORIDADE_VALIDA = "MEDIA";
        const string ESTADO_VALIDO = "FAZENDO";

        const string CODIGO_INVALIDO = "hu123";
        const string TITULO_INVALIDO = "Titulo invalido.";   // termina com ponto
        const string PAPEL_INVALIDO = " Papel";              // inicia com espaco
        const string ACAO_INVALIDA = "acao,,invalida";       // virgula seguida de virgula
        const string VALOR_INVALIDO = "valor invalido.";     // termina com ponto
        const int ESTIMATIVA_INVALIDA = 0;                   // fora de 1..365
        const string PRIORIDADE_INVALIDA = "URGENTE";
        const string ESTADO_INVALIDO = "EM ANDAMENTO";

        const string OUTRO_CODIGO_VALIDO = "HU999";

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};
