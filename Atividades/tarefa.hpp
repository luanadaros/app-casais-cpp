#include <ctime>
#include <string>
#include <vector>
#include "compra.hpp"

using namespace std;

namespace atividades{
    class Tarefa;
}

class Tarefa {
    private:
        string id, idPrestador;
        tm dataInicio;
        int prazoEntrega, numParcelas, qtdParcelasPagas = 0;
        double valorPrestador;
        vector <Compra*> compras;
    
    public:
        Tarefa(string id, string idPrestador, string dataInicio, string prazoEntrega, string valorPrestador, string numParcelas);
        string getIdPrestador();
        double getValorTotal();
        double getValorPrestador();
        double getValorCompras();
        double getGastosMensais(tm data);
        tm getDataInicio();
        void addCompra(Compra& compra);
        void pagarParcela();
        bool temCompras();
        bool comprasEstaoPagas();
        bool tarefaEstaPaga();
};