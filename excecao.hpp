#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <exception>
#include <string>
#include <iostream>

using namespace std;

namespace excecoes{
    class Excecao : public exception {
    protected:
        string mensagem;
    public:
        Excecao(const string& msg);
        friend ostream& operator<<(ostream& os, const Excecao& e);
    };
    
    class ExcecaoIDRepetido : public Excecao {
    public:
        ExcecaoIDRepetido(const string& classe,  const string& id);
    };
    
    class ExcecaoCPFRepetido : public Excecao {
    public:
        ExcecaoCPFRepetido(const string& id, const string& cpf);
    };
    
    class ExcecaoCNPJRepetido : public Excecao {
    public:
        ExcecaoCNPJRepetido(const string& id, const string& cnpj);
    };
    
    class ExcecaoIDNaoCadastrado : public Excecao {
    public:
        ExcecaoIDNaoCadastrado(const string& classe, const string& id, const string& contexto, const string& id2);
    };
    
    class ExcecaoErroFormatacao : public Excecao {
    public:
        ExcecaoErroFormatacao();
    };
    
    class ExcecaoIDLojaInvalido : public Excecao {
        public:
            ExcecaoIDLojaInvalido(const string& idCompra, const string& idLoja);
    };
}

#endif 
