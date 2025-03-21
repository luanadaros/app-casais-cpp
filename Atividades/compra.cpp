#include "compra.hpp"
#include "../Aux_T2/StringUtils.hpp"
#include "../Aux_T2/NumberUtils.hpp"

using namespace cpp_util;

namespace atividades{
    Compra::Compra(string id, string idLoja, string nomeProduto, string qtdProduto, string valorUnitario, string numParcelas)
    : id(id), idLoja(idLoja), nomeProduto(nomeProduto){
        if(isNumber(qtdProduto) && isNumber(numParcelas) && isNumber(valorUnitario)){
            this->valorUnitario = parseDouble(valorUnitario, LOCALE_PT_BR);
            this->qtdProduto = stoi(qtdProduto);
            this->numParcelas = stoi(numParcelas);
            this->qtdParcelasPagas = 0;
        } else {
            //lancar excecao
        }
    }

    string Compra::getIdLoja(){
        return idLoja;
    }

    string Compra::getId(){
        return id;
    }

    double Compra::getValorTotal(){
        return qtdProduto * valorUnitario;
    }

    double Compra::getValorParcela(){
        double valorTotal = getValorTotal();
        return valorTotal / numParcelas;
    }

    int Compra::getNumParcelas(){
        return numParcelas;
    }

    int Compra::getQtdParcelasPagas(){
        return qtdParcelasPagas;
    }

    void Compra::pagarParcela(){
        qtdParcelasPagas++;
    }

    bool Compra::compraEstaPaga(){
        if(qtdParcelasPagas == numParcelas){
            return true;
        } 

        return false;
    }

    Compra::~Compra(){};
}