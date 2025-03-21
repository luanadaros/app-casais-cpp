#include "loja.hpp"

namespace tipo_pessoa {
    Loja::Loja(string id, string nome, string telefone, string endereco, string cnpj) : PessoaJuridica(id, nome, telefone, endereco, cnpj){};

    string Loja::getNome(){
        return nome;
    };

    string Loja::getId(){
        return id;
    }
    
    Loja::~Loja(){}
}