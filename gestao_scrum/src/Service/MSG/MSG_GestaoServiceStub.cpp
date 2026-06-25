#include "MSG_GestaoServiceStub.hpp"
#include "MSC_CadastroServiceStub.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

const int MSG_GestaoServiceStub::TRIGGER_FALHA = 67890;
const int MSG_GestaoServiceStub::TRIGGER_ERRO_SISTEMA = 78901;

int MSG_GestaoServiceStub::extrairGatilhoCodigo(const string& codigo) const {
    string numeros;
    for (size_t i = 0; i < codigo.size(); ++i) {
        if (codigo[i] >= '0' && codigo[i] <= '9') {
            numeros += codigo[i];
        }
    }
    if (numeros.empty()) {
        return -1;
    }
    try {
        return stoi(numeros);
    } catch (...) {
        return -1;
    }
}

void MSG_GestaoServiceStub::verificarGatilho(const string& codigo) const {
    switch (extrairGatilhoCodigo(codigo)) {
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
        default:
            break;
    }
}

bool MSG_GestaoServiceStub::gatilhoFalha(const string& codigo) const {
    return extrairGatilhoCodigo(codigo) == TRIGGER_FALHA;
}

MSG_GestaoServiceStub::HistoriaRegistro* MSG_GestaoServiceStub::buscarHistoria(const string& codigo) {
    for (list<HistoriaRegistro>::iterator it = historias.begin(); it != historias.end(); ++it) {
        if (it->historia->getCodigo() == codigo) {
            return &(*it);
        }
    }
    return nullptr;
}

void MSG_GestaoServiceStub::popularDadosIniciais() {
    ProjetoRegistro projeto;
    projeto.codigo = "AB123";
    projeto.nome = "Gestao Scrum";
    projeto.dataInicio = "01/03/2025";
    projeto.dataTermino = "30/06/2025";
    projetos.push_back(projeto);
    projetosPorPessoa[MSC_CadastroServiceStub::EMAIL_PADRAO].push_back("AB123");

    PlanoRegistro plano;
    plano.codigo = "PS100";
    plano.codigoProjeto = "AB123";
    plano.objetivo = "Entregar autenticacao";
    plano.capacidade = 15;
    planos.push_back(plano);

    HistoriaRegistro h1;
    h1.historia = new HistoriaUsuario();
    h1.historia->setCodigo("HU001");
    h1.historia->setTitulo("Autenticar usuario");
    h1.historia->setPapel("Desenvolvedor");
    h1.historia->setAcao("realizar login");
    h1.historia->setValor("acessar o sistema");
    h1.historia->setEstimativa(3);
    h1.historia->setPrioridade("ALTA");
    h1.codigoProjeto = "AB123";
    h1.codigoPlano = "";
    historias.push_back(h1);

    HistoriaRegistro h2;
    h2.historia = new HistoriaUsuario();
    h2.historia->setCodigo("HU002");
    h2.historia->setTitulo("Cadastrar pessoa");
    h2.historia->setPapel("Proprietario de Produto");
    h2.historia->setAcao("cadastrar usuario");
    h2.historia->setValor("gerenciar equipe");
    h2.historia->setEstimativa(5);
    h2.historia->setPrioridade("MEDIA");
    h2.codigoProjeto = "AB123";
    h2.codigoPlano = "PS100";
    historias.push_back(h2);
}

void MSG_GestaoServiceStub::liberarHistorias() {
    for (list<HistoriaRegistro>::iterator it = historias.begin(); it != historias.end(); ++it) {
        delete it->historia;
    }
    historias.clear();
}

MSG_GestaoServiceStub::MSG_GestaoServiceStub() {
    popularDadosIniciais();
}

MSG_GestaoServiceStub::~MSG_GestaoServiceStub() {
    liberarHistorias();
}

bool MSG_GestaoServiceStub::criarProjeto(Projeto& projeto, const string& emailResponsavel) {
    cout << endl << "MSG_GestaoServiceStub::criarProjeto" << endl;
    verificarGatilho(projeto.getCodigo());
    if (gatilhoFalha(projeto.getCodigo())) {
        return false;
    }
    for (list<ProjetoRegistro>::iterator it = projetos.begin(); it != projetos.end(); ++it) {
        if (it->codigo == projeto.getCodigo()) {
            return false;
        }
    }
    ProjetoRegistro reg;
    reg.codigo = projeto.getCodigo();
    reg.nome = projeto.getNome();
    reg.dataInicio = projeto.getDataInicio();
    reg.dataTermino = projeto.getDataTermino();
    projetos.push_back(reg);
    if (!emailResponsavel.empty()) {
        projetosPorPessoa[emailResponsavel].push_back(reg.codigo);
    }
    return true;
}

bool MSG_GestaoServiceStub::lerProjeto(const string& codigo, ProjetoResumo& resumo) {
    cout << endl << "MSG_GestaoServiceStub::lerProjeto" << endl;
    for (list<ProjetoRegistro>::iterator it = projetos.begin(); it != projetos.end(); ++it) {
        if (it->codigo == codigo) {
            resumo.codigo = it->codigo;
            resumo.nome = it->nome;
            resumo.dataInicio = it->dataInicio;
            resumo.dataTermino = it->dataTermino;
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::atualizarProjeto(const string& codigo, const string& nome) {
    cout << endl << "MSG_GestaoServiceStub::atualizarProjeto" << endl;
    for (list<ProjetoRegistro>::iterator it = projetos.begin(); it != projetos.end(); ++it) {
        if (it->codigo == codigo) {
            it->nome = nome;
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::excluirProjeto(const string& codigo) {
    cout << endl << "MSG_GestaoServiceStub::excluirProjeto" << endl;
    for (list<ProjetoRegistro>::iterator it = projetos.begin(); it != projetos.end(); ++it) {
        if (it->codigo == codigo) {
            projetos.erase(it);
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::criarPlanoSprint(PlanoSprint& plano, const string& codigoProjeto) {
    cout << endl << "MSG_GestaoServiceStub::criarPlanoSprint" << endl;
    verificarGatilho(plano.getCodigo());
    if (gatilhoFalha(plano.getCodigo())) {
        return false;
    }
    for (list<PlanoRegistro>::iterator it = planos.begin(); it != planos.end(); ++it) {
        if (it->codigo == plano.getCodigo()) {
            return false;
        }
    }
    PlanoRegistro reg;
    reg.codigo = plano.getCodigo();
    reg.codigoProjeto = codigoProjeto;
    reg.objetivo = plano.getObjetivo();
    reg.capacidade = plano.getCapacidade();
    planos.push_back(reg);
    return true;
}

bool MSG_GestaoServiceStub::lerPlanoSprint(const string& codigo, PlanoResumo& resumo) {
    cout << endl << "MSG_GestaoServiceStub::lerPlanoSprint" << endl;
    for (list<PlanoRegistro>::iterator it = planos.begin(); it != planos.end(); ++it) {
        if (it->codigo == codigo) {
            resumo.codigo = it->codigo;
            resumo.objetivo = it->objetivo;
            resumo.capacidade = it->capacidade;
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::atualizarPlanoSprint(const string& codigo, const string& objetivo, int capacidade) {
    cout << endl << "MSG_GestaoServiceStub::atualizarPlanoSprint" << endl;
    for (list<PlanoRegistro>::iterator it = planos.begin(); it != planos.end(); ++it) {
        if (it->codigo == codigo) {
            it->objetivo = objetivo;
            it->capacidade = capacidade;
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::excluirPlanoSprint(const string& codigo) {
    cout << endl << "MSG_GestaoServiceStub::excluirPlanoSprint" << endl;
    for (list<PlanoRegistro>::iterator it = planos.begin(); it != planos.end(); ++it) {
        if (it->codigo == codigo) {
            planos.erase(it);
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::criarHistoria(HistoriaUsuario& historia, const string& codigoProjeto) {
    cout << endl << "MSG_GestaoServiceStub::criarHistoria" << endl;
    verificarGatilho(historia.getCodigo());
    if (gatilhoFalha(historia.getCodigo())) {
        return false;
    }
    if (buscarHistoria(historia.getCodigo()) != nullptr) {
        return false;
    }
    HistoriaRegistro reg;
    reg.historia = new HistoriaUsuario();
    reg.historia->setCodigo(historia.getCodigo());
    reg.historia->setTitulo(historia.getTitulo());
    reg.historia->setPapel(historia.getPapel());
    reg.historia->setAcao(historia.getAcao());
    reg.historia->setValor(historia.getValor());
    reg.historia->setEstimativa(historia.getEstimativa());
    reg.historia->setPrioridade(historia.getPrioridade());
    reg.codigoProjeto = codigoProjeto;
    reg.codigoPlano = "";
    historias.push_back(reg);
    return true;
}

HistoriaUsuario* MSG_GestaoServiceStub::lerHistoria(const string& codigo) {
    cout << endl << "MSG_GestaoServiceStub::lerHistoria" << endl;
    HistoriaRegistro* reg = buscarHistoria(codigo);
    if (reg == nullptr) {
        return nullptr;
    }
    return reg->historia;
}

bool MSG_GestaoServiceStub::atualizarHistoria(HistoriaUsuario& historia) {
    cout << endl << "MSG_GestaoServiceStub::atualizarHistoria" << endl;
    HistoriaRegistro* reg = buscarHistoria(historia.getCodigo());
    if (reg == nullptr) {
        return false;
    }
    reg->historia->setTitulo(historia.getTitulo());
    reg->historia->setPapel(historia.getPapel());
    reg->historia->setAcao(historia.getAcao());
    reg->historia->setValor(historia.getValor());
    reg->historia->setEstimativa(historia.getEstimativa());
    reg->historia->setPrioridade(historia.getPrioridade());
    reg->historia->setEstado(historia.getEstado());
    return true;
}

bool MSG_GestaoServiceStub::excluirHistoria(const string& codigo) {
    cout << endl << "MSG_GestaoServiceStub::excluirHistoria" << endl;
    for (list<HistoriaRegistro>::iterator it = historias.begin(); it != historias.end(); ++it) {
        if (it->historia->getCodigo() == codigo) {
            delete it->historia;
            historias.erase(it);
            return true;
        }
    }
    return false;
}

bool MSG_GestaoServiceStub::associarHistoriaPessoa(const string& codigoHistoria, const string& email) {
    cout << endl << "MSG_GestaoServiceStub::associarHistoriaPessoa" << endl;
    HistoriaRegistro* reg = buscarHistoria(codigoHistoria);
    if (reg == nullptr) {
        return false;
    }
    for (size_t i = 0; i < reg->emailsPessoas.size(); ++i) {
        if (reg->emailsPessoas[i] == email) {
            return false;
        }
    }
    reg->emailsPessoas.push_back(email);
    return true;
}

bool MSG_GestaoServiceStub::removerAssociacaoHistoriaPessoa(const string& codigoHistoria, const string& email) {
    cout << endl << "MSG_GestaoServiceStub::removerAssociacaoHistoriaPessoa" << endl;
    HistoriaRegistro* reg = buscarHistoria(codigoHistoria);
    if (reg == nullptr) {
        return false;
    }
    for (vector<string>::iterator it = reg->emailsPessoas.begin(); it != reg->emailsPessoas.end(); ++it) {
        if (*it == email) {
            reg->emailsPessoas.erase(it);
            return true;
        }
    }
    return false;
}

vector<ProjetoResumo> MSG_GestaoServiceStub::listarProjetos() {
    cout << endl << "MSG_GestaoServiceStub::listarProjetos" << endl;
    vector<ProjetoResumo> resultado;
    for (list<ProjetoRegistro>::iterator it = projetos.begin(); it != projetos.end(); ++it) {
        ProjetoResumo resumo;
        resumo.codigo = it->codigo;
        resumo.nome = it->nome;
        resumo.dataInicio = it->dataInicio;
        resumo.dataTermino = it->dataTermino;
        resultado.push_back(resumo);
    }
    return resultado;
}

vector<ProjetoResumo> MSG_GestaoServiceStub::listarProjetosPorPessoa(const string& email) {
    cout << endl << "MSG_GestaoServiceStub::listarProjetosPorPessoa" << endl;
    vector<ProjetoResumo> resultado;
    map<string, vector<string>>::iterator mapIt = projetosPorPessoa.find(email);
    if (mapIt == projetosPorPessoa.end()) {
        return resultado;
    }
    for (size_t i = 0; i < mapIt->second.size(); ++i) {
        ProjetoResumo resumo;
        if (lerProjeto(mapIt->second[i], resumo)) {
            resultado.push_back(resumo);
        }
    }
    return resultado;
}

vector<HistoriaUsuario*> MSG_GestaoServiceStub::listarHistoriasPorProjeto(const string& codigoProjeto) {
    cout << endl << "MSG_GestaoServiceStub::listarHistoriasPorProjeto" << endl;
    verificarGatilho(codigoProjeto);
    if (gatilhoFalha(codigoProjeto)) {
        return vector<HistoriaUsuario*>();
    }
    vector<HistoriaUsuario*> resultado;
    for (list<HistoriaRegistro>::iterator it = historias.begin(); it != historias.end(); ++it) {
        if (it->codigoProjeto == codigoProjeto) {
            resultado.push_back(it->historia);
        }
    }
    return resultado;
}

vector<PlanoResumo> MSG_GestaoServiceStub::listarPlanosPorProjeto(const string& codigoProjeto) {
    cout << endl << "MSG_GestaoServiceStub::listarPlanosPorProjeto" << endl;
    vector<PlanoResumo> resultado;
    for (list<PlanoRegistro>::iterator it = planos.begin(); it != planos.end(); ++it) {
        if (it->codigoProjeto == codigoProjeto) {
            PlanoResumo resumo;
            resumo.codigo = it->codigo;
            resumo.objetivo = it->objetivo;
            resumo.capacidade = it->capacidade;
            resultado.push_back(resumo);
        }
    }
    return resultado;
}

vector<HistoriaUsuario*> MSG_GestaoServiceStub::listarHistoriasPorPlano(const string& codigoPlano) {
    cout << endl << "MSG_GestaoServiceStub::listarHistoriasPorPlano" << endl;
    vector<HistoriaUsuario*> resultado;
    for (list<HistoriaRegistro>::iterator it = historias.begin(); it != historias.end(); ++it) {
        if (it->codigoPlano == codigoPlano) {
            resultado.push_back(it->historia);
        }
    }
    return resultado;
}

vector<HistoriaUsuario*> MSG_GestaoServiceStub::listarHistoriasPorPessoa(const string& email) {
    cout << endl << "MSG_GestaoServiceStub::listarHistoriasPorPessoa" << endl;
    vector<HistoriaUsuario*> resultado;
    for (list<HistoriaRegistro>::iterator it = historias.begin(); it != historias.end(); ++it) {
        for (size_t i = 0; i < it->emailsPessoas.size(); ++i) {
            if (it->emailsPessoas[i] == email) {
                resultado.push_back(it->historia);
                break;
            }
        }
    }
    return resultado;
}

bool MSG_GestaoServiceStub::moverHistoriaParaPlano(const string& codigoHistoria, const string& codigoPlano) {
    cout << endl << "MSG_GestaoServiceStub::moverHistoriaParaPlano" << endl;
    HistoriaRegistro* reg = buscarHistoria(codigoHistoria);
    if (reg == nullptr) {
        return false;
    }
    reg->codigoPlano = codigoPlano;
    return true;
}

bool MSG_GestaoServiceStub::alterarEstadoHistoria(const string& codigoHistoria, const string& estado) {
    cout << endl << "MSG_GestaoServiceStub::alterarEstadoHistoria" << endl;
    HistoriaRegistro* reg = buscarHistoria(codigoHistoria);
    if (reg == nullptr) {
        return false;
    }
    reg->historia->setEstado(estado);
    return true;
}
