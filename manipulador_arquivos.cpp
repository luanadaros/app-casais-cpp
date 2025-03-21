#include "manipulador_arquivos.hpp"
#include <fstream>
#include <iostream>

namespace arquivo{
    void Arquivo::lerArquivo(string caminho, vector <string>& dados){
        ifstream arquivo;
        arquivo.open(caminho, ios::in);
        string linha;
        if(arquivo.is_open()){
            while(!arquivo.eof()){
                getline(arquivo, linha);
                dados.push_back(linha);
            }
        }
    
        arquivo.close();
    
    }
    void Arquivo::escreverArquivoEstatisticaCasais(string caminho);
    void Arquivo::escreverArquivoEstatisticaPrestadores(string caminho);
    void Arquivo::escreverArquivoPlanejamento(string caminho);
}