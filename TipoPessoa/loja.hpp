#ifndef LOJA_HPP
#define LOJA_HPP

#include <string>
#include "pessoa_juridica.hpp"

namespace tipo_pessoa{
    class Loja: public PessoaJuridica {
        public:
            Loja(string id, string nome, string telefone, string endereco, string cnpj);
            string getNome();
            string getId();
            ~Loja();
    };
}

#endif