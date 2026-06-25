#pragma once



#include "IMSC_CadastroService.hpp"



#include <list>

#include <stdexcept>

#include <string>



using namespace std;



/**

 * @class MSC_CadastroServiceStub

 * @ingroup msc

 * @brief Implementacao stub do servico de cadastro de pessoas (MSC).

 *

 * Armazena pessoas em lista e implementa CRUD, listagem e validacao

 * de credenciais. Inclui usuario padrao para testes e gatilhos no email.

 */

class MSC_CadastroServiceStub : public IMSC_CadastroService {

private:

    static const int TRIGGER_FALHA;        ///< Gatilho: retorna falha na operacao.

    static const int TRIGGER_ERRO_SISTEMA; ///< Gatilho: lanca erro de sistema.



    struct PessoaCadastrada {

        string email;

        string nome;

        string senha;

        string papel;

    };



    list<PessoaCadastrada> pessoas; ///< Armazenamento em memoria das pessoas.



    int extrairGatilho(const string& email) const;

    bool emailExiste(const string& email) const;

    void popularUsuarioPadrao();



public:

    static const string EMAIL_PADRAO; ///< Email do usuario padrao de teste.

    static const string SENHA_PADRAO; ///< Senha do usuario padrao de teste.



    /** @brief Constroi o stub populando o usuario padrao. */

    MSC_CadastroServiceStub();



    /** @brief Cria uma nova pessoa no armazenamento em memoria. */

    bool criarPessoa(Pessoa& pessoa) override;



    /** @brief Le resumo de pessoa pelo email. */

    bool lerPessoa(const string& email, PessoaResumo& resumo) override;



    /** @brief Atualiza nome e papel de pessoa existente. */

    bool atualizarPessoa(const string& email, const string& nome, const string& papel) override;



    /** @brief Exclui pessoa pelo email. */

    bool excluirPessoa(const string& email) override;



    /** @brief Lista todas as pessoas cadastradas. */

    vector<PessoaResumo> listarPessoas() override;



    /** @brief Valida credenciais de acesso de uma pessoa. */

    bool validarCredenciais(

        const string& email,

        const string& senha,

        string& nomeUsuario,

        string& papelUsuario) override;

};

