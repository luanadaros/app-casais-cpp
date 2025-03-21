#include "tarefa.hpp"
#include "../Aux_T2/StringUtils.hpp"
#include "../Aux_T2/NumberUtils.hpp"
#include "../Aux_T2/DateUtils.hpp"

using namespace cpp_util;

namespace atividades{
    Tarefa::Tarefa(string id, string idPrestador, string dataInicio, string prazoEntrega, string valorPrestador, string numParcelas)
    : id(id), idPrestador(idPrestador){
        if(validDate(dataInicio, DATE_FORMAT_PT_BR_SHORT) && isNumber(prazoEntrega) && isNumber(valorPrestador) && isNumber(numParcelas)){
            this->dataInicio = parseDate(dataInicio, DATE_FORMAT_PT_BR_SHORT);
            this->valorPrestador = parseDouble(valorPrestador, LOCALE_PT_BR);
            this->prazoEntrega = stoi(prazoEntrega);
            this->numParcelas = stoi(numParcelas);
            this->qtdParcelasPagas = 0;
        } else {
            // lancar excecao
        }
    }

    string Tarefa::getIdPrestador(){
        return idPrestador;
    }

    double Tarefa::getValorTotal(){
        double valor = 0.0;

        valor += valorPrestador;
        for(Compra * compra : compras){
            valor += compra->getValorTotal();
        }

        return valor;
    }

    double Tarefa::getValorPrestador(){
        return valorPrestador;
    }

    double Tarefa::getValorCompras(){
        double valor = 0.0;
        for(Compra * compra : compras){
            valor += compra->getValorTotal();
        }
        return valor;
    }

    double Tarefa::getGastosMensais(time_t data){
        tm * dt = localtime(&data);
        tm * dt2 = localtime(&dataInicio);
        int mesData = dt->tm_mon + 1;
        int anoData = dt->tm_year + 1900;
        int mesThisData = dt2->tm_mon + 1;
        int anoThisData = dt2->tm_year + 1900;

        double gastosMensais = 0.0;

        if(temCompras()){
            for(Compra * compra : compras){
                if(!compra->compraEstaPaga()){
                    if(anoData == anoThisData && mesThisData <= mesData && ((mesThisData + compra->getNumParcelas()) > mesData)){
                        gastosMensais += compra->getValorParcela();
                        compra->pagarParcela();
                    } else if (anoThisData != anoData && ((mesThisData + compra->getNumParcelas() - 12) > mesData)){
                        gastosMensais += compra->getValorParcela();
                        compra->pagarParcela();
                    }
                }
            }
        }

        if(!tarefaEstaPaga()){
            if(anoData == anoThisData && mesThisData <= mesData && ((mesThisData + numParcelas) > mesData)){
                gastosMensais += valorPrestador/numParcelas;
                pagarParcela();
            } else if (anoThisData != anoData && ((mesThisData + numParcelas - 12) > mesData)){
                gastosMensais += valorPrestador/numParcelas;
                pagarParcela();
            }
        }

        return gastosMensais;
    }

    time_t Tarefa::getDataInicio(){
        return dataInicio;
    }

    void Tarefa::addCompra(Compra& compra){
        compras.push_back(&compra);
    }

    void Tarefa::pagarParcela(){
        qtdParcelasPagas++;
    }

    bool Tarefa::temCompras(){
        return compras.empty();
    }

    bool Tarefa::comprasEstaoPagas(){
        for(Compra * compra : compras){
            if(!compra->compraEstaPaga()){
                return false;
            }
        }

        return true;
    }

    bool Tarefa::tarefaEstaPaga(){
        if(comprasEstaoPagas() && (qtdParcelasPagas == numParcelas)){
            return true;
        }

        return false;
    }
}