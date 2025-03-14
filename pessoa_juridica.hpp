#include <string>
using namespace std;

class PessoaJuridica {
    private:
        string id, nome, telefone, endereco, cnpj;
    public:
        PessoaJuridica(string, string, string, string, string);
        string getNome();
        static bool comparaCnpj(PessoaJuridica, PessoaJuridica);
        ~PessoaJuridica();
};

class Loja: public PessoaJuridica {
    public:
        Loja(string, string, string, string, string);
        string getNome();
        string getId();
        ~Loja();
};

