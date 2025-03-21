#include <iostream>
#include "manipulador_arquivos.hpp"
#include "cadastro.hpp"
#include "excecao.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace arquivo;
using namespace cadastro;
using namespace excecoes;

int main(int argc, char**argv){
    if(argc < 2){
        cout << "Pasta nao informada.\n";
    }
    string pasta = argv[1];
    vector<string> dadosPessoas, dadosLares, dadosTarefas, dadosCasamentos,
    dadosFestas, dadosCompras;
    Arquivo * manipuladorArquivo = new Arquivo();
    Cadastro * bancoDeDados = new Cadastro();
    try{
        manipuladorArquivo->lerArquivo(pasta + "pessoas.csv", dadosPessoas);
        manipuladorArquivo->lerArquivo(pasta + "lares.csv", dadosLares);
        manipuladorArquivo->lerArquivo(pasta + "tarefas.csv", dadosTarefas);
        manipuladorArquivo->lerArquivo(pasta + "casamentos.csv", dadosCasamentos);
        manipuladorArquivo->lerArquivo(pasta + "festas.csv", dadosFestas);
        manipuladorArquivo->lerArquivo(pasta + "compras.csv", dadosCompras);

        try {
            bancoDeDados->cadastraPessoas(dadosPessoas);
            bancoDeDados->cadastraLares(dadosLares);
            bancoDeDados->cadastraCasamentos(dadosCasamentos);
            bancoDeDados->cadastraTarefas(dadosTarefas);
            bancoDeDados->cadastraCompras(dadosCompras);
            bancoDeDados->cadastraFestas(dadosFestas);
        } catch (Excecao &e){
            cout << e;
            delete manipuladorArquivo;
            delete bancoDeDados;
            exit(EXIT_FAILURE);
        }

    } catch (exception& e){
        cout << "Erro de I/O.\n";
    }

    delete manipuladorArquivo;
    delete bancoDeDados;
}