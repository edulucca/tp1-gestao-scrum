#pragma once
#include "Texto.hpp"

using namespace std;

///Classe criada para testar os cenários de sucesso e falha de uso de parâmetros da classe-domínio "Texto".
class TextoTest {

private:
    Texto* texto;
    int estado;

    const static int SUCESSO = 0;
    const static int FALHA = -1;

///Casos de teste que possuem textos válidos, com o número máximo de caracteres e contendo dígitos, espaços, pontos e vírgulas.

    const string TEXTO_VALIDO1 = "Texto com quarenta caracteres.Vai Passar";
    const string TEXTO_VALIDO2 = "Texto menor, com dígitos 123";

///Casos de teste com textos inválidos: maiores do que o permitido, com caracteres vedados, com espaço antes de pontuação e com ponto ao final da string.
    const string TEXTO_INVALIDO1 = "Texto com mais do que quarenta caracteres";
    const string TEXTO_INVALIDO2 = " Espaço no início";
    const string TEXTO_INVALIDO3 = "Caracteres invalidos: $%";
    const string TEXTO_INVALIDO4 = "Ponto no final.";
    const string TEXTO_INVALIDO5 = "Espaco antes do ponto .Nao passa";

public:
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    int run();
};
