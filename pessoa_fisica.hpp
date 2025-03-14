#include <string>
#include <ctime>
using namespace std;

class PessoaFisica {
    private:
        string id, nome, cpf, telefone, endereco;
        double poupanca, salario, gastosMensais;
        tm dataNascimento;
    public:
        PessoaFisica(string, string, string, string, string, string, string, string, string);
        string getNome();
        string getCpf();
        double getGastosMensais();
        double getPoupanca();
        double getSalario();
        double getDecimoTerceiro(int);
        void atualizaPoupanca(double);
        void atualizaPoupancaRendimento();
        static bool compara_cpf(PessoaFisica, PessoaFisica);
        ~PessoaFisica();
};