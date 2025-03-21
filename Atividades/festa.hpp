#ifndef FESTA_HPP
#define FESTA_HPP

#include <string>
#include <ctime>
#include <vector>

using namespace std;

namespace atividades{
    class Festa {
        private:
            string id, local, hora;
            time_t data;
            double preco, valorParcela;
            int numParcelas, qtdParcelasPagas = 0, qtdConvidados;
            vector <string*> convidados;
        public:
            Festa(string id, string local, string data, string hora, string preco, string numParcelas, string qtdConvidados);
            string getId();
            double getValorTotal();
            double getValorParcela();
            vector <string*> getConvidados();
            int getNumParcelas();
            int getQtdParcelasPagas();
            time_t getData();
            double getGastosMensais(time_t data);
            void addConvidado(string& convidado);
            void pagarParcela();
            bool festaEstaPaga();
            ~Festa();
    };
}


#endif