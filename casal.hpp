#include <string>
#include <ctime>
#include "pessoa_fisica.hpp"
#include "casamento.hpp"
using namespace std;

class Casal{
    private:
        PessoaFisica p1, p2;
        Casamento casamento;
        //NovoLar novoLar;
    
    public:
        Casal(PessoaFisica, PessoaFisica);
        void setCasamento(Casamento);
        //void setNovoLar(NovoLar);

        void atualizaPoupancaCasal(double);
        void atualizaRendimentoPoupancaCasal();
        string getNomeP1();
        string getNomeP2();
        string getCpfP1();
        string getCpfP2();
        Casamento getCasamento();
        //NovoLar getNovoLar();
        tm getDataFesta();
        tm getMenorDataInicioTarefas();
        tm getDataInicioPlanejamento();

        bool temCasamento();
        bool temNovoLar();
        bool temFesta();
        bool temTarefas();
        bool contasEstaoPagas();

        double calculaGastosMensais(tm data);
        double calculaSaldosMensais(tm data);
        ~Casal();
};