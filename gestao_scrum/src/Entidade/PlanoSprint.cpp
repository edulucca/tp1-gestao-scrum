/**
 * @file PlanoSprint.cpp
 * @brief Implementacao da entidade PlanoSprint de forma encapsulada.
 */
#include "PlanoSprint.hpp"
#include "Codigo.hpp"
#include "Texto.hpp"
#include "Tempo.hpp"

using namespace std;

/** @brief Estrutura interna que agrega os dominios do plano de sprint. */
struct PlanoSprint::Impl {
    Codigo codigo;      ///< Codigo identificador (chave primaria).
    Texto objetivo;     ///< Objetivo do sprint.
    Tempo capacidade;   ///< Capacidade em dias.
};

/** @brief Constroi o plano de sprint alocando a implementacao interna. */
PlanoSprint::PlanoSprint() : impl(new Impl()) {}

/** @brief Libera a memoria da implementacao interna. */
PlanoSprint::~PlanoSprint() {
    delete impl;
}

/**
 * @brief Define o codigo do plano de sprint (nao pode ser redefinido).
 * @throw invalid_argument Se ja estiver definido ou for invalido.
 */
void PlanoSprint::setCodigo(const string& codigo) {
    if (!impl->codigo.getCodigo().empty()) {
        throw invalid_argument("Codigo ja definido para este projeto.");
    }
    impl->codigo.setCodigo(codigo);
}

/**
 * @brief Define o objetivo do plano de sprint.
 * @throw invalid_argument Se o objetivo for invalido.
 */
void PlanoSprint::setObjetivo(const string& objetivo) {
    impl->objetivo.setTexto(objetivo);
}

/**
 * @brief Define a capacidade do plano de sprint em dias.
 * @throw invalid_argument Se estiver fora do intervalo 1 a 365.
 */
void PlanoSprint::setCapacidade(int capacidade) {
    impl->capacidade.setTempo(capacidade);
}

/**
 * @brief Obtem o codigo do plano de sprint.
 * @return Codigo atual (ex.: retorna "PS001").
 */
string PlanoSprint::getCodigo() const {
    return impl->codigo.getCodigo();
}

/**
 * @brief Obtem o objetivo do plano de sprint.
 * @return Objetivo atual (ex.: retorna "Entregar o cadastro de contas").
 */
string PlanoSprint::getObjetivo() const {
    return impl->objetivo.getTexto();
}

/**
 * @brief Obtem a capacidade do plano de sprint em dias.
 * @return Numero de dias atual (ex.: retorna 15).
 */
int PlanoSprint::getCapacidade() const {
    return impl->capacidade.getTempo();
}
