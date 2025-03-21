#include "novo_lar.hpp"
#include <limits>

namespace evento{
    NovoLar::NovoLar(string id, string rua, string numero, string complemento)
    : id(id), rua(rua), numero(numero), complemento(complemento){}

    void NovoLar::addTarefa(Tarefa& tarefa){
        tarefas.push_back(&tarefa);
    }

    double NovoLar::getValorTotalTarefas(){
        double valor = 0.0;
        for(Tarefa * tarefa : tarefas){
            valor += tarefa->getValorTotal();
        }
        return valor;
    }

    double NovoLar::getGastosMensais(time_t data){
        double gastos = 0.0;
        for(Tarefa * tarefa : tarefas){
            gastos += tarefa->getGastosMensais(data);
        }
        return gastos;
    }

    time_t NovoLar::getMenorDataInicioTarefa(){
        time_t menorData = numeric_limits<time_t>::max();

        for (auto& t : tarefas) {
            if (t->getDataInicio() < menorData) {
                menorData = t->getDataInicio();
            }
        }
        return menorData;
    }

    bool NovoLar::temTarefas(){
        return !tarefas.empty();
    }

    bool NovoLar::tarefasEstaoPagas(){
        for(Tarefa * tarefa : tarefas){
            if(!tarefa->tarefaEstaPaga()){
                return false;
            }
        }
        return true;
    }

    bool NovoLar::comprasEstaoPagas(){
        for(Tarefa * tarefa : tarefas){
            if(!tarefa->comprasEstaoPagas()){
                return false;
            }
        }
        return true;
    }
}