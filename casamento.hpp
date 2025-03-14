#include <string>
#include <ctime>
using namespace std;

class Casamento{
    private:
        string id, local;
        tm data;
        //Festa festa;
    public:
        Casamento(string, string, string, string);
        bool temFesta();
        bool temConvidado(string);
        bool festaEstaPaga();
        //void set_festa(Festa);
        double getValorFesta();
        double getGastosMensais(tm data);
        tm getDataFesta();
        ~Casamento();
};