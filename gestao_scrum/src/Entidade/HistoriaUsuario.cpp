#include "HistoriaUsuario.hpp"

// especificação exige que ao criar historia do usuario, o po associe ela o estado A FAZER

HistoriaUsuario::HistoriaUsuario() {
    Estado estadoInicial;
    estadoInicial.setEstado("A FAZER");
    this->estado = estadoInicial;
}

HistoriaUsuario::~HistoriaUsuario() {

}

// metodos set

void HistoriaUsuario::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

void HistoriaUsuario::setTitulo(const Texto& titulo) {
    this->titulo = titulo;
}

void HistoriaUsuario::setPapel(const Texto& papel) {
    this->papel = papel;
}

void HistoriaUsuario::setAcao(const Texto& acao) {
    this->acao = acao;
}

void HistoriaUsuario::setValor(const Texto& valor) {
    this->valor = valor;
}

void HistoriaUsuario::setEstimativa(const Tempo& estimativa) {
    this->estimativa = estimativa;
}

void HistoriaUsuario::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}

void HistoriaUsuario::setEstado(const Estado& estado) {
    this->estado = estado;
}

// metodos get

Codigo HistoriaUsuario::getCodigo() const {
    return codigo;
}

Texto HistoriaUsuario::getTitulo() const {
    return titulo;
}

Texto HistoriaUsuario::getPapel() const {
    return papel;
}

Texto HistoriaUsuario::getAcao() const {
    return acao;
}

Texto HistoriaUsuario::getValor() const {
    return valor;
}

Tempo HistoriaUsuario::getEstimativa() const {
    return estimativa;
}

Prioridade HistoriaUsuario::getPrioridade() const {
    return prioridade;
}

Estado HistoriaUsuario::getEstado() const {
    return estado;
}