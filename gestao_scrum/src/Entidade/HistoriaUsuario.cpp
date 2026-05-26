/**
 * @file HistoriaUsuario.cpp
 * @brief Implementacao da entidade HistoriaUsuario de forma encapsulada.
 */
#include "HistoriaUsuario.hpp"
#include "Codigo.hpp"
#include "Texto.hpp"
#include "Tempo.hpp"
#include "Prioridade.hpp"
#include "Estado.hpp"

using namespace std;

/** @brief Estrutura interna que agrega os dominios da historia de usuario. */
struct HistoriaUsuario::Impl {
    Codigo codigo;          ///< Codigo identificador (chave primaria).
    Texto titulo;           ///< Titulo da historia.
    Texto papel;            ///< Papel (parte "como...").
    Texto acao;             ///< Acao (parte "eu quero...").
    Texto valor;            ///< Valor (parte "para...").
    Tempo estimativa;       ///< Estimativa em dias.
    Prioridade prioridade;  ///< Prioridade da historia.
    Estado estado;          ///< Estado atual da historia.
};

// especificacao exige que ao criar historia do usuario, associe ela ao estado A FAZER

/** @brief Constroi a historia de usuario com estado inicial "A FAZER". */
HistoriaUsuario::HistoriaUsuario() : impl(new Impl()) {
    impl->estado.setEstado("A FAZER");
}

/** @brief Libera a memoria da implementacao interna. */
HistoriaUsuario::~HistoriaUsuario() {
    delete impl;
}

/**
 * @brief Define o codigo do plano de sprint (nao pode ser redefinido).
 * @throw invalid_argument Se ja estiver definido ou for invalido.
 */
void HistoriaUsuario::setCodigo(const string& codigo) {
    if (!impl->codigo.getCodigo().empty()) {
        throw invalid_argument("Codigo ja definido para este projeto.");
    }
    impl->codigo.setCodigo(codigo);
}

/**
 * @brief Define o titulo da historia.
 * @throw invalid_argument Se o titulo for invalido.
 */
void HistoriaUsuario::setTitulo(const string& titulo) {
    impl->titulo.setTexto(titulo);
}

/**
 * @brief Define o papel da historia (parte "como...").
 * @throw invalid_argument Se o papel for invalido.
 */
void HistoriaUsuario::setPapel(const string& papel) {
    impl->papel.setTexto(papel);
}

/**
 * @brief Define a acao da historia (parte "eu quero...").
 * @throw invalid_argument Se a acao for invalida.
 */
void HistoriaUsuario::setAcao(const string& acao) {
    impl->acao.setTexto(acao);
}

/**
 * @brief Define o valor da historia (parte "para...").
 * @throw invalid_argument Se o valor for invalido.
 */
void HistoriaUsuario::setValor(const string& valor) {
    impl->valor.setTexto(valor);
}

/**
 * @brief Define a estimativa da historia em dias.
 * @throw invalid_argument Se estiver fora do intervalo 1 a 365.
 */
void HistoriaUsuario::setEstimativa(int estimativa) {
    impl->estimativa.setTempo(estimativa);
}

/**
 * @brief Define a prioridade da historia.
 * @throw invalid_argument Se a prioridade for invalida.
 */
void HistoriaUsuario::setPrioridade(const string& prioridade) {
    impl->prioridade.setPrioridade(prioridade);
}

/**
 * @brief Define o estado da historia.
 * @throw invalid_argument Se o estado for invalido.
 */
void HistoriaUsuario::setEstado(const string& estado) {
    impl->estado.setEstado(estado);
}

/**
 * @brief Obtem o codigo da historia.
 * @return Codigo atual (ex.: retorna "HU001").
 */
string HistoriaUsuario::getCodigo() const {
    return impl->codigo.getCodigo();
}

/**
 * @brief Obtem o titulo da historia.
 * @return Titulo atual (ex.: retorna "Criar conta de usuario").
 */
string HistoriaUsuario::getTitulo() const {
    return impl->titulo.getTexto();
}

/**
 * @brief Obtem o papel da historia.
 * @return Papel atual (ex.: retorna "Proprietario de Produto").
 */
string HistoriaUsuario::getPapel() const {
    return impl->papel.getTexto();
}

/**
 * @brief Obtem a acao da historia.
 * @return Acao atual (ex.: retorna "cadastrar uma conta").
 */
string HistoriaUsuario::getAcao() const {
    return impl->acao.getTexto();
}

/**
 * @brief Obtem o valor da historia.
 * @return Valor atual (ex.: retorna "acessar os servicos").
 */
string HistoriaUsuario::getValor() const {
    return impl->valor.getTexto();
}

/**
 * @brief Obtem a estimativa da historia em dias.
 * @return Numero de dias atual (ex.: retorna 5).
 */
int HistoriaUsuario::getEstimativa() const {
    return impl->estimativa.getTempo();
}

/**
 * @brief Obtem a prioridade da historia.
 * @return Prioridade atual (ex.: retorna "ALTA").
 */
string HistoriaUsuario::getPrioridade() const {
    return impl->prioridade.getPrioridade();
}

/**
 * @brief Obtem o estado da historia.
 * @return Estado atual (ex.: retorna "FAZENDO").
 */
string HistoriaUsuario::getEstado() const {
    return impl->estado.getEstado();
}
