#include "pessoa_juridica.hpp"

namespace tipo_pessoa {
    PessoaJuridica::PessoaJuridica(string id, string nome, string telefone, string endereco, string cnpj)
        : id(id), nome(nome), telefone(telefone), endereco(endereco), cnpj(cnpj) {
    }

    //gets
    string PessoaJuridica::getNome(){
        return nome;
    }

    //compare
    bool PessoaJuridica::comparaCNPJ(PessoaJuridica* p1, PessoaJuridica* p2){
        return p1->cnpj == p2->cnpj;
    }

    PessoaJuridica::~PessoaJuridica(){}
}