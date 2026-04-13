#include <iostream>
#include <string>
#include "Codigo.hpp"

using namespace std;

int main()
{
    string palavra = "AB123";

    Codigo codigo;



    try{
        codigo.setCodigo(palavra);
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what();
        return 0;
    }
    return 0;
}
