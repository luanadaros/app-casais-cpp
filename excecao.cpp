#include <iostream>
#include <exception>
#include <string>

#include "excecao.hpp"

namespace excecoes{
    Excecao::Excecao(const string& msg) : mensagem(msg) {}
    ExcecaoIDRepetido::ExcecaoIDRepetido(const string& classe, const string& id): Excecao("ID repetido " + id + " na classe " + classe + ".") {}
    ExcecaoCPFRepetido::ExcecaoCPFRepetido(const string& id, const string& cpf) : Excecao("O CPF " + cpf + " da Pessoa " + id + " é repetido.") {}
    ExcecaoCNPJRepetido::ExcecaoCNPJRepetido(const string& id, const string& cnpj) : Excecao("O CNPJ " + cnpj + " da Pessoa " + id + " é repetido.") {}
    ExcecaoIDNaoCadastrado::ExcecaoIDNaoCadastrado(const string& classe, const string& id, const string& contexto, const string& id2) : Excecao("ID(s) de " + classe + " " + id + " não cadastrado " + contexto + " " + id2 + ".") {}
    ExcecaoErroFormatacao::ExcecaoErroFormatacao() : Excecao("Erro de formatação.") {}
    ExcecaoIDLojaInvalido::ExcecaoIDLojaInvalido(const string& idCompra, const string& idLoja) : Excecao("ID " + idLoja + " da Compra de ID " + idCompra + " não se refere a uma Loja, mas a uma PJ.") {}

    ostream& operator<<(ostream& os, const Excecao& e){
        os<< e.mensagem << endl;
        return os;
    }
}

