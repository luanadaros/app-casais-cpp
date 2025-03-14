#include <string>
#include <ctime>
#include "Atividades/festa.hpp"
using namespace std;

namespace evento{
    class Casamento;
}

class Casamento{
    private:
        string id, local;
        tm data;
        Festa* festa;
    public:
        Casamento(string, string, string, string);
        bool temFesta();
        bool temConvidado(string);
        bool festaEstaPaga();
        void set_festa(Festa&);
        double getValorFesta();
        double getGastosMensais(tm data);
        tm getDataFesta();
        ~Casamento();
};