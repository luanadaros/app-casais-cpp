#include "festa.hpp"
#include "../Aux_T2/DateUtils.hpp"
#include "../Aux_T2/NumberUtils.hpp"
#include "../Aux_T2/StringUtils.hpp"

using namespace cpp_util;

namespace atividades{
    Festa::Festa(string id, string local, string data, string hora, string preco, string numParcelas, string qtdConvidados)
    : id(id), local(local), hora(hora){
        if(validDate(data, DATE_FORMAT_PT_BR_SHORT) && isNumber(preco) && isNumber(numParcelas) && isNumber(qtdConvidados)){
            this->data = parseDate(data, DATE_FORMAT_PT_BR_SHORT);
            this->preco = parseDouble(preco, LOCALE_PT_BR);
            this->numParcelas = stoi(numParcelas);
            this->qtdConvidados = stoi(qtdConvidados);
            this->qtdParcelasPagas = 0;
        } else {
            //lancar excecao
        }
    }

    string Festa::getId(){
        return id;
    }

    double Festa::getValorTotal(){
        return preco;
    }

    double Festa::getValorParcela(){
        return getValorTotal() / numParcelas;
    }

    vector <string*> Festa::getConvidados(){
        return convidados;
    }

    int Festa::getNumParcelas(){
        return numParcelas;
    }

    int Festa::getQtdParcelasPagas(){
        return qtdParcelasPagas;
    }

    time_t Festa::getData(){
        return data;
    }

    double Festa::getGastosMensais(time_t data){
        tm* dt = localtime(&data);
        tm* dt2 = localtime(&this->data);

        int mesData = dt->tm_mon + 1;
        int anoData = dt->tm_year + 1900;
        int mesThisData = dt2->tm_mon + 1;
        int anoThisData = dt2->tm_year + 1900;

        if(anoData == anoThisData && mesThisData <= mesData && ((mesThisData + this->numParcelas) > mesData)){
            this->pagarParcela();
            return this->getValorParcela();
        } else if(anoThisData != anoData && ((mesThisData + this->numParcelas - 12) > mesData)){
            this->pagarParcela();
            return this->getValorParcela();
        }

        return 0.0;
    }

    void Festa::addConvidado(string& convidado){
        convidados.push_back(&convidado);
    }

    void Festa::pagarParcela(){
        qtdParcelasPagas++;
    }

    bool Festa::festaEstaPaga(){
        if(qtdParcelasPagas == numParcelas){
            return true;
        }

        return false;
    }
    
    Festa::~Festa(){};
}