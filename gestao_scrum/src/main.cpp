#include <iostream>
#include <string>
#include "Codigo.hpp"
#include "Nome.hpp"
#include "Estado.hpp"

using namespace std;

int main()
{
    // Valida codigo
    string palavra = "AB123";
    Codigo codigo;

    // Valida nome
    string meuNome = "Luis Serra";
    Nome nome;

    // Valida estado
    string meuEstado1 = "A FAZER";
    string meuEstado2 = "FAZENDO";
    string meuEstado3 = "FEITO";
    Estado estado;

    try{
        nome.setNome(meuNome);
        cout << "Nome valido: " << nome.getNome() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what() << endl;
        return 0;
    }

    try{
        codigo.setCodigo(palavra);
        cout << "Codigo valido: " << codigo.getCodigo() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what();
        return 0;
    }

    try{
        estado.setEstado(meuEstado1);
        cout << "Estado valido: " << estado.getEstado() << endl;
        estado.setEstado(meuEstado2);
        cout << "Estado valido: " << estado.getEstado() << endl;
        estado.setEstado(meuEstado3);
        cout << "Estado valido: " << estado.getEstado() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what() << endl;
        return 0;
    }


    return 0;
}
