/**
 * @file Projeto.cpp
 * @brief Implementacao da entidade Projeto de forma encapsulada.
 */
#include "Projeto.hpp"
#include "Nome.hpp"
#include "Data.hpp"
#include "Codigo.hpp"

using namespace std;

/** @brief Estrutura interna que agrega os dominios do projeto. */
struct Projeto::Impl {
    Nome nome;          ///< Nome do projeto.
    Codigo codigo;      ///< Codigo identificador (chave primaria).
    Data dataInicio;    ///< Data de inicio.
    Data dataTermino;   ///< Data de termino.
};

/** @brief Constroi o projeto alocando a implementacao interna. */
Projeto::Projeto() : impl(new Impl()) {}

/** @brief Libera a memoria da implementacao interna. */
Projeto::~Projeto(){
    delete impl;
}

/**
 * @brief Define o nome do projeto.
 * @throw invalid_argument Se o nome for invalido.
 */
void Projeto::setNome(const string& nome){
    impl->nome.setNome(nome);
}

/**
 * @brief Define o codigo do projeto (nao pode ser redefinido).
 * @throw invalid_argument Se ja estiver definido ou for invalido.
 */
void Projeto::setCodigo(const string& codigo) {
    if (!impl->codigo.getCodigo().empty()) {
        throw invalid_argument("Codigo ja definido para este projeto.");
    }
    impl->codigo.setCodigo(codigo);
}

/**
 * @brief Obtem o codigo do projeto.
 * @return Codigo atual (ex.: retorna "PR001").
 */
string Projeto::getCodigo() const {
    return impl->codigo.getCodigo();
}

/**
 * @brief Define a data de inicio do projeto.
 * @throw invalid_argument Se a data for invalida.
 */
void Projeto::setDataInicio(const string& data){
    impl->dataInicio.setData(data);
}


/**
 * @brief Define a data de termino do projeto.
 * @throw invalid_argument Se a data for invalida.
 */
void Projeto::setDataTermino(const string& data){
    impl->dataTermino.setData(data);
}

/**
 * @brief Obtem o nome do projeto.
 * @return Nome atual (ex.: retorna "Pro Scrum").
 */
string Projeto::getNome() const {
    return impl->nome.getNome();
}

/**
 * @brief Obtem a data de inicio do projeto.
 * @return Data de inicio (ex.: retorna "01/03/2025").
 */
string Projeto::getDataInicio() const {
    return impl->dataInicio.getData();
}

/**
 * @brief Obtem a data de termino do projeto.
 * @return Data de termino (ex.: retorna "30/06/2025").
 */
string Projeto::getDataTermino() const {
    return impl->dataTermino.getData();
}
