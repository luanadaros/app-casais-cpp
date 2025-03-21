#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace arquivo {
    class Arquivo {
        public:
            void lerArquivo(string caminho, vector <string>& dados);
            void escreverArquivoEstatisticaCasais(string caminho);
            void escreverArquivoEstatisticaPrestadores(string caminho);
            void escreverArquivoPlanejamento(string caminho);
    };
}


#endif