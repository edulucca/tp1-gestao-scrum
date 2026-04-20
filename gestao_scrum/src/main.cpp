#include <iostream>
#include <string>
#include "Codigo.hpp"
#include "Nome.hpp"
#include "Estado.hpp"
#include "Papel.hpp"
#include "Prioridade.hpp"
#include "Data.hpp"


using namespace std;

int main()
{
    // Valida codigo
    string palavra = "AB123";
    Codigo codigo;

    try{
        codigo.setCodigo(palavra);
        cout << "Codigo valido: " << codigo.getCodigo() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what();
        return 0;
    }

    // Valida nome
    string meuNome = "Luis Serra";
    Nome nome;

    try{
        nome.setNome(meuNome);
        cout << "Nome valido: " << nome.getNome() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what() << endl;
        return 0;
    }

    // Valida estado
    string meuEstado1 = "A FAZER";
    string meuEstado2 = "FAZENDO";
    string meuEstado3 = "FEITO";
    Estado estado;

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

    // Valida papel
    string meuPapel1 = "DESENVOLVEDOR";
    string meuPapel2 = "MESTRE SCRUM";
    string meuPapel3 = "PROPRIETARIO DE PRODUTO";
    Papel papel;

    try{
        papel.setPapel(meuPapel1);
        cout << "Papel valido: " << papel.getPapel() << endl;
        papel.setPapel(meuPapel2);
        cout << "Papel valido: " << papel.getPapel() << endl;
        papel.setPapel(meuPapel3);
        cout << "Papel valido: " << papel.getPapel() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what() << endl;
        return 0;
    }

    // Valida prioridade
    string minhaPrioridade1 = "ALTA";
    string minhaPrioridade2 = "MEDIA";
    string minhaPrioridade3 = "BAIXA";
    Prioridade prioridade;

    try{
        prioridade.setPrioridade(minhaPrioridade1);
        cout << "Prioridade valida: " << prioridade.getPrioridade() << endl;
        prioridade.setPrioridade(minhaPrioridade2);
        cout << "Prioridade valida: " << prioridade.getPrioridade() << endl;
        prioridade.setPrioridade(minhaPrioridade3);
        cout << "Prioridade valida: " << prioridade.getPrioridade() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what() << endl;
        return 0;
    }

    // Valida data
    string minhaData1 = "29/02/2024";
    string minhaData2 = "1/03/2024";
    string minhaData3 = "pa/di/2099";
    Data data;

    try{
        data.setData(minhaData1);
        cout << "Data valida: " << data.getData() << endl;
        data.setData(minhaData2);
        cout << "Data valida: " << data.getData() << endl;
        data.setData(minhaData3);
        cout << "Data valida: " << data.getData() << endl;
    } catch (const invalid_argument& error){
        cerr << "Erro: " << error.what() << endl;
        return 0;
    }

    return 0;
}
