#include "casal.hpp"

using namespace tipo_pessoa;

namespace casal{
    Casal::Casal(tipo_pessoa::PessoaFisica* p1, tipo_pessoa::PessoaFisica* p2){
        this->p1 = p1;
        this->p2 = p2;
        this->casamento = nullptr;
        this->novoLar = nullptr;
    }

    void Casal::setCasamento(evento::Casamento* casamento){
        this->casamento = casamento;
    }
    void Casal::setNovoLar(evento::NovoLar* lar){
        this->novoLar = lar;
    }

    void Casal::atualizaPoupancaCasal(double valor){
        p1->atualizaPoupanca(valor/2);
        p2->atualizaPoupanca(valor/2);
    }

    void Casal::atualizaRendimentoPoupancaCasal(){
        p1->atualizaPoupancaRendimento();
        p2->atualizaPoupancaRendimento();
    }

    string Casal::getNomeP1(){
        return p1->getNome();
    }

    string Casal::getNomeP2(){
        return p2->getNome();
    }

    string Casal::getCpfP1(){
        return p1->getCPF();
    }

    string Casal::getCpfP2(){
        return p2->getCPF();
    }

    evento::Casamento * Casal::getCasamento(){
        return casamento;
    }

    evento::NovoLar * Casal::getNovoLar(){
        return novoLar;
    }

    time_t Casal::getDataFesta(){
        return casamento->getDataFesta();
    }

    time_t Casal::getMenorDataInicioTarefas(){
        if(this->temTarefas()){
            return novoLar->getMenorDataInicioTarefa();
        }

        return 0;
    }

    time_t Casal::getDataInicioPlanejamento(){
        time_t menorData = getMenorDataInicioTarefas();

        if(menorData != 0 && menorData > casamento->getDataFesta()){
            return casamento->getDataFesta();
        }

        return menorData;
    }

    bool Casal::temCasamento(){
        return casamento != nullptr;
    }

    bool Casal::temNovoLar(){
        return novoLar != nullptr;
    }

    bool Casal::temFesta(){
        return casamento->temFesta();
    }

    bool Casal::temTarefas(){
        return novoLar->temTarefas();
    }

    bool Casal::contasEstaoPagas(){
        bool condicao1 = true;
        bool condicao2 = true;

        if(temTarefas()){
            condicao1 = novoLar->tarefasEstaoPagas() && novoLar->comprasEstaoPagas();
        }

        if(temFesta()){
            condicao2 = casamento->festaEstaPaga();
        }

        return condicao1 && condicao2;
    }

    double Casal::calculaGastosMensais(time_t data){
        double gastos = 0.0;
        if(temCasamento()){
            gastos += casamento->getGastosMensais(data);
        }
        if(temNovoLar()){
            gastos += novoLar->getGastosMensais(data);
        }
        return gastos;
    }

    double Casal::calculaSaldosMensais(time_t data, double gastos){
        tm * dt = localtime(&data);
        int mes = dt->tm_mon + 1;

        gastos += p1->getGastosMensais();
        gastos += p2->getGastosMensais();

        double contaP1 = p1->getPoupanca() + p1->getSalario() + p1->getDecimoTerceiro(mes);
        double contaP2 = p2->getPoupanca() + p2->getSalario() + p2->getDecimoTerceiro(mes);

        double saldo = contaP1 + contaP2 - gastos;
        atualizaPoupancaCasal(saldo);

        return saldo;
    }

    Casal::~Casal(){};
}