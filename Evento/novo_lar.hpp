#include <string>
#include <vector>
#include <ctime>
#include "tarefa.hpp"
using namespace std;

namespace evento{
    class NovoLar;
}
class NovoLar {
    private:
        string id, rua, numero, complemento;
        vector <Tarefa&> tarefas;

    public:
        NovoLar(string id, string rua, string numero, string complemento);
        double getValorTotalTarefas();
        double getGastosMensais(tm data);
        tm getMenorDataInicioTarefa();
        void addTarefa(Tarefa& tarefa);
        bool temTarefas();
        bool tarefasEstaoPagas();
        bool comprasEstaoPagas();
};