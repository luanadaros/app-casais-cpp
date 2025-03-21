#ifndef CASAMENTO_HPP
#define CASAMENTO_HPP

#include <string>
#include <ctime>
#include "../Atividades/festa.hpp"
using namespace std;

namespace evento{
    class Casamento{
        private:
            string id, hora, local;
            time_t data;
            atividades::Festa* festa;
        public:
            Casamento(string id, string data, string hora, string local);
            bool temFesta();
            bool temConvidado(string nomeConvidado);
            bool festaEstaPaga();
            void setFesta(atividades::Festa& festa);
            double getValorFesta();
            double getGastosMensais(time_t data);
            time_t getDataFesta();
            ~Casamento();
    };
}

#endif