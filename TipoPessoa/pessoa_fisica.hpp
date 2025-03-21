#ifndef PESSOA_FISICA_HPP
#define PESSOA_FISICA_HPP

#include <string>
#include <ctime>
using namespace std;

namespace tipo_pessoa{
    class PessoaFisica {
        private:
            string id, nome, telefone, endereco, cpf;
            time_t dataNascimento;
            double poupanca, salario, gastosMensais;
        public:
            PessoaFisica(string id, string nome, string telefone, string endereco, string cpf, string dataNascimento, string poupanca, string salario, string gastosMensais);
            string getNome();
            string getCPF();
            double getGastosMensais();
            double getPoupanca();
            double getSalario();
            double getDecimoTerceiro(int mes);
            void atualizaPoupanca(double valor);
            void atualizaPoupancaRendimento();
            static bool comparaCPF(PessoaFisica* p1, PessoaFisica* p2);
            ~PessoaFisica();
    };
}

#endif