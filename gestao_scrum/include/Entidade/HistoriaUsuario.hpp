#ifndef HISTORIADEUSUARIO_HPP_INCLUDED
#define HISTORIADEUSUARIO_HPP_INCLUDED

// #pragma once

#include <string>

// include de dominios

#include "Codigo.hpp"
#include "Texto.hpp"
#include "Tempo.hpp"
#include "Prioridade.hpp"
#include "Estado.hpp"

using namespace std;

class HistoriaUsuario{
    private:
        Codigo codigo;
        Texto titulo;
        Texto papel;
        Texto acao;
        Texto valor;
        Tempo estimativa;
        Prioridade prioridade;
        Estado estado;

    public:
        // constrtores e destrutores

        HistoriaUsuario();
        ~HistoriaUsuario();

        // metodos set

        void setCodigo(const Codigo& codigo);
        void setTitulo(const Texto& titulo);
        void setPapel(const Texto& papel);
        void setAcao(const Texto& acao);
        void setValor(const Texto& valor);
        void setEstimativa(const Tempo& estimativa);
        void setPrioridade(const Prioridade& prioridade);
        void setEstado(const Estado& estado);

        // metodos get
        Codigo getCodigo() const;
        Texto getTitulo() const;
        Texto getPapel() const;
        Texto getAcao() const;
        Texto getValor() const;
        Tempo getEstimativa() const;
        Prioridade getPrioridade() const;
        Estado getEstado() const;
};

#endif // HISTORIADEUSUARIO_HPP_INCLUDED