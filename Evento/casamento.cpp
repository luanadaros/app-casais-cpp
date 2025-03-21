#include "casamento.hpp"
#include "../Aux_T2/DateUtils.hpp"
#include "../Aux_T2/StringUtils.hpp"

using namespace cpp_util;

namespace evento{
    Casamento::Casamento(string id, string data, string hora, string local)
    : id(id), hora(hora), local(local){
        if(validDate(data, DATE_FORMAT_PT_BR_SHORT)){
            this->data = parseDate(data, DATE_FORMAT_PT_BR_SHORT);
        } else {
            //lancar excecao
        }
    }

    bool Casamento::temFesta(){
        return festa != nullptr;
    }

    bool Casamento::temConvidado(string nomeConvidado){
        if(temFesta()){
            for(string * convidado : festa->getConvidados()){
                if(stringCompare(*convidado, nomeConvidado)){
                    return true;
                }
            }
        }
        return false;
    }

    bool Casamento::festaEstaPaga(){
        return festa->festaEstaPaga();
    }

    void Casamento::setFesta(atividades::Festa& festa){
        this->festa = &festa;
    }

    double Casamento::getValorFesta(){
        return festa->getValorTotal();
    }

    double Casamento::getGastosMensais(time_t data){
        double gastos = 0.0;
        if(temFesta()){
            gastos += festa->getGastosMensais(data);
        }
        return gastos;
    }

    time_t Casamento::getDataFesta(){
        return festa->getData();
    }

    Casamento::~Casamento(){};
}