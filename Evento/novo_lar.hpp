#ifndef LAR_HPP
#define LAR_HPP

#include <string>
#include <vector>
#include <ctime>
#include "../Atividades/tarefa.hpp"
using namespace std;
using namespace atividades;

namespace evento{
    class NovoLar {
        private:
            string id, rua, numero, complemento;
            vector <Tarefa*> tarefas;
    
        public:
            NovoLar(string id, string rua, string numero, string complemento);
            double getValorTotalTarefas();
            double getGastosMensais(time_t data);
            time_t getMenorDataInicioTarefa();
            void addTarefa(Tarefa& tarefa);
            bool temTarefas();
            bool tarefasEstaoPagas();
            bool comprasEstaoPagas();
    }; 
}

#endif