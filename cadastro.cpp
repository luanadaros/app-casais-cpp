#include "cadastro.hpp"
#include "Aux_T2/StringUtils.hpp"
#include <iostream>
#include <sstream>
#include <map>
#include "excecao.hpp"

using namespace std;
using namespace cpp_util;
using namespace tipo_pessoa;
using namespace excecoes;

namespace cadastro{
    //adds
    Cadastro::Cadastro() {}

    void Cadastro::addPessoaFisica(string id, PessoaFisica* pessoa) {
        pessoasFisicas[id] = pessoa;
    }
    
    void Cadastro::addPessoaJuridica(string id, PessoaJuridica* pessoa) {
        pessoasJuridicas[id] = pessoa;
    }
    
    void Cadastro::addLoja(string id, Loja* loja) {
        lojas[id] = loja;
    }
    
    void Cadastro::addCasal(string idP1, string idP2, Casal* casal) {
        casais[idP1] = casal;
        casais[idP2] = casal;
    }
    
    void Cadastro::addCompra(string id, Compra* compra) {
        compras[id] = compra;
    }
    
    void Cadastro::addFesta(string id, Festa* festa) {
        festas[id] = festa;
    }
    
    void Cadastro::addTarefa(string id, Tarefa* tarefa) {
        tarefas[id] = tarefa;
    }
    
    void Cadastro::addNovoLar(string id, NovoLar* novoLar) {
        novosLares[id] = novoLar;
    }
    
    void Cadastro::addCasamento(string id, Casamento* casamento) {
        casamentos[id] = casamento;
    }
    
    //gets
    PessoaFisica* Cadastro::getPessoaFisica(string id) {
        return pessoasFisicas.count(id) ? pessoasFisicas[id] : nullptr;
    }
    
    PessoaJuridica* Cadastro::getPessoaJuridica(string id) {
        return pessoasJuridicas.count(id) ? pessoasJuridicas[id] : nullptr;
    }
    
    Casal* Cadastro::getCasal(string id) {
        return casais.count(id) ? casais[id] : nullptr;
    }

    NovoLar* Cadastro::getLar(string id) {
        return novosLares.count(id) ? novosLares[id] : nullptr;
    }
    
    Casamento* Cadastro::getCasamento(string id){
        return casamentos.count(id) ? casamentos[id] : nullptr;
    }

    Tarefa * Cadastro::getTarefa(string id){
        return tarefas.count(id) ? tarefas[id] : nullptr;
    }

    map<string, Casal*> Cadastro::getMapCasais() {
        return casais;
    }
    
    map<string, Casamento*> Cadastro::getMapCasamentos() {
        return casamentos;
    }
    
    map<string, Festa*> Cadastro::getMapFestas() {
        return festas;
    }
    
    map<string, Tarefa*> Cadastro::getMapTarefas() {
        return tarefas;
    }
    
    map<string, NovoLar*> Cadastro::getMapNovosLares() {
        return novosLares;
    }
    
    map<string, Compra*> Cadastro::getMapCompras() {
        return compras;
    }
    
    map<string, Loja*> Cadastro::getMapLojas() {
        return lojas;
    }
    
    map<string, PessoaFisica*> Cadastro::getMapPessoasFisicas() {
        return pessoasFisicas;
    }
    
    map<string, PessoaJuridica*> Cadastro::getMapPessoasJuridicas() {
        return pessoasJuridicas;
    }
    
    bool Cadastro::verificaIdPessoas(string id) {
        if (pessoasFisicas.empty() && pessoasJuridicas.empty() && lojas.empty()) {
            return false;
        }
        return pessoasFisicas.find(id) != pessoasFisicas.end() ||
           pessoasJuridicas.find(id) != pessoasJuridicas.end() ||
           lojas.find(id) != lojas.end();
    }
    
    bool Cadastro::verificaIdLares(string id) {
        if(novosLares.empty()){
            return false;
        }
        return novosLares.count(id);
    }
    
    bool Cadastro::verificaIdCasamentos(string id) {
        if(casamentos.empty()){
            return false;
        }
        return casamentos.count(id);
    }
    
    bool Cadastro::verificaIdTarefas(string id) {
        if(tarefas.empty()){
            return false;
        }
        return tarefas.count(id);
    }
    
    bool Cadastro::verificaIdFestas(string id) {
        if(festas.empty()){
            return false;
        }
        return festas.count(id);
    }
    
    bool Cadastro::verificaIdCompras(string id) {
        if(compras.empty()){
            return false;
        }
        return compras.count(id);
    }
    
    bool Cadastro::verificaCPF(PessoaFisica* pf) {
        if (pessoasFisicas.empty()) return false;

        for (auto p2 : pessoasFisicas) {
            if (PessoaFisica::comparaCPF(pf, p2.second)) {
                return true;
            }
        }
        return false;
    }
    
    bool Cadastro::verificaCNPJ(PessoaJuridica* pj) {
        if (pessoasJuridicas.empty()) return false;

        for (auto p2 : pessoasJuridicas) {
            if (PessoaJuridica::comparaCNPJ(pj, p2.second)) {
                return true;
            }
        }
        return false;
    }
    
    void Cadastro::cadastraPessoas(vector <string> dados){
        for(auto pessoa: dados){
            trim(pessoa);
            if(pessoa.empty()){
                continue;
            }
            stringstream ss(pessoa);
            vector<string> itens;
            string item;
    
            while(getline(ss,item,';')){
                itens.push_back(item);
            }
    
            string id = itens[0];
            if(this->verificaIdPessoas(id)){
                string classe = "Pessoa";
                throw ExcecaoIDRepetido(classe, id);
            } else {
                string tipoF = "F";
                string tipoJ = "J";

                if(itens[1] == tipoF){
                    //pessoa fisica
                    PessoaFisica * pf = new PessoaFisica(itens[0], itens[2], itens[3], itens[4], itens[5], itens[6], itens[7], itens[8], itens[9]);
                    if(this->verificaCPF(pf)){
                        delete pf;
                        throw ExcecaoCPFRepetido(itens[0], itens[5]);
                    } else{
                        this->addPessoaFisica(itens[0], pf);
                    }
                } else if(itens[1] == tipoJ){
                    //pessoa juridica
                    PessoaJuridica * pj = new PessoaJuridica(itens[0], itens[2], itens[3], itens[4], itens[5]);
                    if(this->verificaCNPJ(pj)){
                        delete pj;
                        throw ExcecaoCNPJRepetido(itens[0], itens[5]);
                    } else{
                        this->addPessoaJuridica(itens[0], pj);
                    }
                } else{
                    //loja
                    Loja * loja = new Loja(itens[0], itens[2], itens[3], itens[4], itens[5]);
                    this->addLoja(itens[0], loja);
                }
            }
        }
    }

    void Cadastro::cadastraLares(vector <string> dados){
        for(auto lar: dados){
            trim(lar);
            if(lar.empty()){
                continue;
            }
            stringstream ss(lar);
            vector<string> itens;
            string item;
    
            while(getline(ss,item,';')){
                itens.push_back(item);
            }
    
            string id = itens[0];
            string idP1 = itens[1];
            string idP2 = itens[2];
            Casal* casal;

            if(this->verificaIdLares(id)){
                string classe = "Lar";
                throw ExcecaoIDRepetido(classe, id);
            } else {
                if(!verificaIdPessoas(idP1) && !verificaIdPessoas(idP2)){
                    string classe = "Pessoa";
                    string ids = idP1 + " " + idP2;
                    string contexto = "no Lar de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else if(!verificaIdPessoas(idP1)){
                    string classe = "Pessoa";
                    string ids = idP1;
                    string contexto = "no Lar de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else if(!verificaIdPessoas(idP2)){
                    string classe = "Pessoa";
                    string ids = idP2;
                    string contexto = "no Lar de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else{
                    if(this->getCasal(idP1) == nullptr && this->getCasal(idP2) == nullptr){
                        PessoaFisica * p1 = this->getPessoaFisica(idP1);
                        PessoaFisica * p2 = this->getPessoaFisica(idP2);

                        casal = new Casal(p1, p2);
                        this->addCasal(idP1, idP2, casal);
                    } else{
                        casal = this->getCasal(idP1);
                    }

                    NovoLar* novoLar = new NovoLar(itens[0], itens[3], itens[4], itens[5]);
                    casal->setNovoLar(novoLar);
                    this->addNovoLar(itens[0], novoLar);
                }
            }
        }
    }

    void Cadastro::cadastraCasamentos(vector <string> dados){
        for(auto casamento: dados){
            trim(casamento);
            if(casamento.empty()){
                continue;
            }
            stringstream ss(casamento);
            vector<string> itens;
            string item;
    
            while(getline(ss,item,';')){
                itens.push_back(item);
            }
    
            string id = itens[0];
            string idP1 = itens[1];
            string idP2 = itens[2];
            Casal* casal;

            if(this->verificaIdCasamentos(id)){
                string classe = "Casamento";
                throw ExcecaoIDRepetido(classe, id);
            } else {
                if(!verificaIdPessoas(idP1) && !verificaIdPessoas(idP2)){
                    string classe = "Pessoa";
                    string ids = idP1 + " " + idP2;
                    string contexto = "no Casamento de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else if(!verificaIdPessoas(idP1)){
                    string classe = "Pessoa";
                    string ids = idP1;
                    string contexto = "no Casamento de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else if(!verificaIdPessoas(idP2)){
                    string classe = "Pessoa";
                    string ids = idP2;
                    string contexto = "no Casamento de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else{
                    if(this->getCasal(idP1) == nullptr && this->getCasal(idP2) == nullptr){
                        PessoaFisica * p1 = this->getPessoaFisica(idP1);
                        PessoaFisica * p2 = this->getPessoaFisica(idP2);

                        casal = new Casal(p1, p2);
                        this->addCasal(idP1, idP2, casal);
                    } else{
                        casal = this->getCasal(idP1);
                    }

                    Casamento* cas = new Casamento(itens[0], itens[3], itens[4], itens[5]);
                    casal->setCasamento(cas);
                    this->addCasamento(itens[0], cas);
                }
            }
        }
    }

    void Cadastro::cadastraTarefas(vector <string> dados){
        for(auto tarefa: dados){
            trim(tarefa);
            if(tarefa.empty()){
                continue;
            }

            stringstream ss(tarefa);
            vector<string> itens;
            string item;
    
            while(getline(ss,item,';')){
                itens.push_back(item);
            }
    
            string id = itens[0];
            string idLar = itens[1];
            string idPrestador = itens[2];

            if(verificaIdTarefas(id)){
                string classe = "Tarefa";
                throw ExcecaoIDRepetido(classe, id);
            } else {
                if(!verificaIdLares(idLar)){
                    string classe = "Lar";
                    string ids = idLar;
                    string contexto = "na Tarefa de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else if(!verificaIdPessoas(idPrestador)){
                    string classe = "Prestador de Serviço";
                    string ids = idPrestador;
                    string contexto = "na Tarefa de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else {
                    NovoLar * lar = this->getLar(idLar);
                    Tarefa* novaTarefa = new Tarefa(itens[0], itens[2], itens[3], itens[4], itens[5], itens[6]);
                    lar->addTarefa(*novaTarefa);
                    this->addTarefa(itens[0], novaTarefa);
                }
            }
        }
    }

    void Cadastro::cadastraFestas(vector <string> dados){
        for(auto festa: dados){
            trim(festa);
            if(festa.empty()){
                continue;
            }

            stringstream ss(festa);
            vector<string> itens;
            string item;
    
            while(getline(ss,item,';')){
                itens.push_back(item);
            }
    
            string id = itens[0];
            string idCasamento = itens[1];

            if(verificaIdFestas(id)){
                string classe = "Festa";
                throw ExcecaoIDRepetido(classe, id);
            } else {
                if(!verificaIdCasamentos(idCasamento)){
                    string classe = "Casamento";
                    string ids = idCasamento;
                    string contexto = "na Festa de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else {
                    Casamento * cas = this->getCasamento(idCasamento);
                    Festa* novaFesta = new Festa(itens[0], itens[2], itens[3], itens[4], itens[5], itens[6], itens[7]);
                    int numConvidados = stoi(itens[7]);

                    for(int i = 8; i < 8 + numConvidados; i++){
                        novaFesta->addConvidado(itens[i]);
                    }

                    cas->setFesta(*novaFesta);
                    this->addFesta(itens[0], novaFesta);
                }
            }
        }
    }
    
    void Cadastro::cadastraCompras(vector <string> dados){
        for(auto compra:dados){
            trim(compra);
            if(compra.empty()){
                continue;
            }
            stringstream ss(compra);
            vector<string> itens;
            string item;
    
            while(getline(ss,item,';')){
                itens.push_back(item);
            }
    
            string id = itens[0];
            string idTarefa = itens[1];
            string idLoja = itens[2];

            if(verificaIdCompras(id)){
                string classe = "Compra";
                throw ExcecaoIDRepetido(classe, id);
            } else {
                if(!verificaIdTarefas(idTarefa)){
                    string classe = "Tarefa";
                    string ids = idTarefa;
                    string contexto = "na Compra de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else if(this->pessoasJuridicas.count(idLoja) > 0){
                    throw ExcecaoIDLojaInvalido(id, idLoja);
                } else if(this->lojas.count(idLoja) == 0){
                    string classe = "Loja";
                    string ids = idLoja;
                    string contexto = "na Compra de ID";
                    throw ExcecaoIDNaoCadastrado(classe, ids, contexto, id);
                } else {
                    Tarefa * tarefa = this->getTarefa(idTarefa);
                    Compra * novaCompra = new Compra(itens[0], itens[2], itens[3], itens[4], itens[5], itens[6]);
                    tarefa->addCompra(*novaCompra);
                    this->addCompra(itens[0], novaCompra);
                }
            }
        }
    }
    
    void Cadastro::liberarPessoasFisicas() {
        for (auto par : pessoasFisicas) {
            delete par.second;
        }

        pessoasFisicas.clear();
    }
    
    void Cadastro::liberarPessoasJuridicas() {
        for (auto par : pessoasJuridicas) {
            delete par.second;
        }

        pessoasJuridicas.clear();
    }
    
    void Cadastro::liberarLojas() {
        for (auto par : lojas) {
            delete par.second;
        }

        lojas.clear();
    }
    
    void Cadastro::liberarCasais() {
        map<Casal*, bool> jaDeletados;
    
        for (const auto& par : casais) {
            Casal* casal = par.second;
            if (jaDeletados.find(casal) == jaDeletados.end()) {
                delete casal;
                jaDeletados[casal] = true;
            }
        }
    
        casais.clear(); 
    }
    
    void Cadastro::liberarCasamentos() {
        for (auto par : casamentos) {
            delete par.second;
        }

        casamentos.clear();
    }
    
    void Cadastro::liberarTarefas() {
        for (auto par : tarefas) {
            delete par.second;
        }

        tarefas.clear();
    }
    
    void Cadastro::liberarCompras() {
        for (auto par : compras) {
            delete par.second;
        }

        compras.clear();
    }
    
    void Cadastro::liberarFestas() {
        for (auto par : festas) {
            delete par.second;
        }

        festas.clear();
    }
    
    void Cadastro::liberarNovosLares() {
        for (auto par : novosLares) {
            delete par.second;
        }

        novosLares.clear();
    }

    void Cadastro::liberarMemoria() {
        liberarPessoasFisicas();
        liberarPessoasJuridicas();
        liberarLojas();
        liberarCasais();
        liberarCasamentos();
        liberarTarefas();
        liberarCompras();
        liberarFestas();
        liberarNovosLares();
    }

    Cadastro::~Cadastro() {
        liberarMemoria();
    }
}
