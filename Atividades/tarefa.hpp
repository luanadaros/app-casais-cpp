#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <ctime>
#include <string>
#include <vector>
#include "compra.hpp"

using namespace std;

namespace atividades{
    class Tarefa {
        private:
            string id, idPrestador;
            time_t dataInicio;
            int prazoEntrega, numParcelas, qtdParcelasPagas = 0;
            double valorPrestador;
            vector <Compra*> compras;
        
        public:
            Tarefa(string id, string idPrestador, string dataInicio, string prazoEntrega, string valorPrestador, string numParcelas);
            string getIdPrestador();
            double getValorTotal();
            double getValorPrestador();
            double getValorCompras();
            double getGastosMensais(time_t data);
            time_t getDataInicio();
            void addCompra(Compra& compra);
            void pagarParcela();
            bool temCompras();
            bool comprasEstaoPagas();
            bool tarefaEstaPaga();
    };
}

#endif