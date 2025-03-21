#ifndef CASAL_HPP
#define CASAL_HPP

#include <string>
#include <ctime>
#include "../TipoPessoa/pessoa_fisica.hpp"
#include "../Evento/casamento.hpp"
#include "../Evento/novo_lar.hpp"

using namespace std;

namespace casal { 
    class Casal{
        private:
            tipo_pessoa::PessoaFisica *p1, *p2;
            evento::Casamento * casamento;
            evento::NovoLar * novoLar;
        
        public:
            Casal(tipo_pessoa::PessoaFisica* p1, tipo_pessoa::PessoaFisica* p2);
            void setCasamento(evento::Casamento* casamento);
            void setNovoLar(evento::NovoLar* lar);
    
            void atualizaPoupancaCasal(double valor);
            void atualizaRendimentoPoupancaCasal();
            string getNomeP1();
            string getNomeP2();
            string getCpfP1();
            string getCpfP2();
            evento::Casamento * getCasamento();
            evento::NovoLar * getNovoLar();
            time_t getDataFesta();
            time_t getMenorDataInicioTarefas();
            time_t getDataInicioPlanejamento();
    
            bool temCasamento();
            bool temNovoLar();
            bool temFesta();
            bool temTarefas();
            bool contasEstaoPagas();
    
            double calculaGastosMensais(time_t data);
            double calculaSaldosMensais(time_t data, double gastos);
            ~Casal();
    };
}

#endif