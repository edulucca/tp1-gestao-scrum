#pragma once
#include "Texto.hpp"

using namespace std;

///Classe criada para testar os cen�rios de sucesso e falha de uso de parametros da classe-dom�nio "Texto".
class TextoTest {

private:
    Texto* texto;
    int estado;

    const static int SUCESSO = 0;
    const static int FALHA = -1;

///Casos de teste que possuem textos validos, com o n�mero m�ximo de caracteres e contendo d�gitos, espa�os, pontos e v�rgulas.

    const string TEXTO_VALIDO1 = "Texto com quarenta caracteres.Vai Passar";
    const string TEXTO_VALIDO2 = "Texto com digitos 123";

///Casos de teste com textos invalidos: maiores do que o permitido, com caracteres vedados, com espa�o antes de pontuacao e com ponto ao final da string.
    const string TEXTO_INVALIDO1 = "Texto com mais do que quarenta caracteres";
    const string TEXTO_INVALIDO2 = " Espaco no inicio do texto";
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
