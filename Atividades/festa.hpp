#include <string>
#include <ctime>
#include <vector>

using namespace std;

namespace atividades{
    class Festa;
}

class Festa {
    private:
        string id, local;
        tm data, hora;
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
        tm getData();
        double getGastosMensais(tm data);
        void addConvidado(string& convidado);
        void pagarParcela();
        bool festaEstaPaga();
        ~Festa();
};