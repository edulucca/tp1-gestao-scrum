#include <iostream>
#include <stdexcept>
#include "Pessoa.hpp"

using namespace std;

static void testarValido(const string& descricao,
                         const string& strEmail,
                         const string& strNome,
                         const string& strSenha,
                         const string& strPapel) {
    try {


        Pessoa pessoa;
        pessoa.setEmail(strEmail);
        pessoa.setNome(strNome);
        pessoa.setSenha(strSenha);
        pessoa.setPapel(strPapel);

        cout << "[PASSOU] " << descricao << endl;
        cout << "  email=" << pessoa.getEmail()
             << " nome="  << pessoa.getNome()
             << " papel=" << pessoa.getPapel() << endl;
    } catch (const invalid_argument& ex) {
        cout << "[FALHOU] " << descricao << " -> " << ex.what() << endl;
    }
}

static void testarInvalido(const string& descricao,
                           const string& strEmail,
                           const string& strNome,
                           const string& strSenha,
                           const string& strPapel) {
    try {
        Pessoa pessoa;
        pessoa.setEmail(strEmail);
        pessoa.setNome(strNome);
        pessoa.setSenha(strSenha);
        pessoa.setPapel(strPapel);


        cout << "[FALHOU] " << descricao << " -> excecao esperada, nao lancada" << endl;
    } catch (const invalid_argument& ex) {
        cout << "[PASSOU] " << descricao << " -> " << ex.what() << endl;
    }
}

int main() {
    cout << "=== TESTES VALIDOS ===" << endl;

    testarValido("Desenvolvedor basico",
        "luis@unb.br", "Luis", "a1B2c3", "DESENVOLVEDOR");

    testarValido("Mestre Scrum nome com espaco",
        "maria.silva@empresa.com", "Maria S", "A1b2C3", "MESTRE SCRUM");

    testarValido("Proprietario de Produto nome maximo",
        "jo.ao-123@sub.dom.br", "Joao Silva", "1a2B3c", "PROPRIETARIO DE PRODUTO");

    testarValido("Senha comeca com digito",
        "dev@x.io", "Dev", "1A2b3C", "DESENVOLVEDOR");

    cout << endl << "=== TESTES INVALIDOS ===" << endl;

    testarInvalido("Email sem arroba",
        "emailinvalido", "Luis", "a1B2c3", "DESENVOLVEDOR");

    testarInvalido("Email local inicia com ponto",
        ".luis@unb.br", "Luis", "a1B2c3", "DESENVOLVEDOR");

    testarInvalido("Email dominio inicia com hifen",
        "luis@-unb.br", "Luis", "a1B2c3", "DESENVOLVEDOR");

    testarInvalido("Nome vazio",
        "luis@unb.br", "", "a1B2c3", "DESENVOLVEDOR");

    testarInvalido("Nome excede 10 caracteres",
        "luis@unb.br", "NomeMuitoLongo", "a1B2c3", "DESENVOLVEDOR");

    testarInvalido("Nome inicia com espaco",
        "luis@unb.br", " Luis", "a1B2c3", "DESENVOLVEDOR");

    testarInvalido("Senha menor que 6 caracteres",
        "luis@unb.br", "Luis", "a1B2c", "DESENVOLVEDOR");

    testarInvalido("Senha duas letras seguidas",
        "luis@unb.br", "Luis", "ab1C2d", "DESENVOLVEDOR");

    testarInvalido("Senha dois digitos seguidos",
        "luis@unb.br", "Luis", "a12B3c", "DESENVOLVEDOR");

    testarInvalido("Senha sem letra maiuscula",
        "luis@unb.br", "Luis", "a1b2c3", "DESENVOLVEDOR");

    testarInvalido("Senha sem letra minuscula",
        "luis@unb.br", "Luis", "A1B2C3", "DESENVOLVEDOR");

    testarInvalido("Senha sem digito",
        "luis@unb.br", "Luis", "aAbBcC", "DESENVOLVEDOR");

    testarInvalido("Papel invalido",
        "luis@unb.br", "Luis", "a1B2c3", "GERENTE");

    return 0;
}
