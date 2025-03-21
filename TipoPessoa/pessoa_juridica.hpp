#ifndef PESSOA_JURIDICA_HPP
#define PESSOA_JURIDICA_HPP

#include <string>
using namespace std;

namespace tipo_pessoa{
    class PessoaJuridica {
        private:
            string id, nome, telefone, endereco, cnpj;
        public:
            PessoaJuridica(string id, string nome, string telefone, string endereco, string cnpj);
            string getNome();
            static bool comparaCNPJ(PessoaJuridica* p1, PessoaJuridica* p2);
            ~PessoaJuridica();
            friend class Loja;
    };
}

#endif