#include <string>
using namespace std;

namespace atividades{
    class Compra;
}

class Compra{
    private:
        string id, idLoja, nomeProduto;
        int qtdProduto, numParcelas, qtdParcelasPagas = 0;
        double valorUnitario;
    
    public:
        Compra(string id, string idLoja, string nomeProduto, string qtdProduto, string valorUnitario, string numParcelas);
        string getIdLoja();
        string getId();
        double getValorTotal();
        double getValorParcela();
        int getNumParcelas();
        int getQtdParcelasPagas();
        void pagarParcela();
        bool compraEstaPaga();
        ~Compra();
};
