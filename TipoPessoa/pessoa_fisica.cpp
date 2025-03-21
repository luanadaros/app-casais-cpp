#include "pessoa_fisica.hpp"
#include "../Aux_T2/DateUtils.hpp"
#include "../Aux_T2/NumberUtils.hpp"

using namespace cpp_util;

namespace tipo_pessoa{
    PessoaFisica::PessoaFisica(string id, string nome, string telefone, string endereco, string cpf, string dataNascimento, 
                               string poupanca, string salario, string gastosMensais)
        : id(id), nome(nome), telefone(telefone), endereco(endereco), cpf(cpf) {
        this->dataNascimento = parseDate(dataNascimento, DATE_FORMAT_PT_BR_SHORT);
        this->poupanca = parseDouble(poupanca, LOCALE_PT_BR);
        this->salario = parseDouble(salario, LOCALE_PT_BR);
        this->gastosMensais = parseDouble(gastosMensais, LOCALE_PT_BR);
    }
    
    //gets
    string PessoaFisica::getNome() {
        return nome;
    }
    
    string PessoaFisica::getCPF() {
        return cpf;
    }
    
    double PessoaFisica::getGastosMensais() {
        return gastosMensais;
    }
    
    double PessoaFisica::getPoupanca() {
        return poupanca;
    }
    
    double PessoaFisica::getSalario() {
        return salario;
    }
    
    double PessoaFisica::getDecimoTerceiro(int mes) {
        if (mes == 12 && salario > 0) {
            return salario;
        }
        return 0.0;
    }
    
    //sets
    void PessoaFisica::atualizaPoupanca(double valor) {
        this->poupanca = valor;
        this->atualizaPoupancaRendimento();
    }
    
    void PessoaFisica::atualizaPoupancaRendimento() {
        poupanca += poupanca * 0.005;
    }
    
    //compares
    bool PessoaFisica::comparaCPF(PessoaFisica* p1, PessoaFisica* p2) {
        return p1->cpf == p2->cpf;
    }

    PessoaFisica::~PessoaFisica(){}
    
}    
