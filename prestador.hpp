#include <string>
#include "TipoPessoa/pessoa_fisica.hpp"
#include "TipoPessoa/pessoa_juridica.hpp"

class Prestador {
    public:
        //definir operador >> para imprimir prestador no arquivo

};

class PrestadorPF: public Prestador, public PessoaFisica{

};

class PrestadorPJ: public Prestador, public PessoaJuridica{

};

class PrestadorLoja: public Prestador, public Loja{

};
