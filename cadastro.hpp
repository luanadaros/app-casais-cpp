#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "TipoPessoa/pessoa_fisica.hpp"
#include "TipoPessoa/pessoa_juridica.hpp"
#include "Evento/casamento.hpp"
#include "Evento/novo_lar.hpp"
#include "Atividades/tarefa.hpp"
#include "Atividades/compra.hpp"
#include "Atividades/festa.hpp"
#include "Casal/casal.hpp"

using namespace std;

class Cadastro {
    private:
        map<string, PessoaFisica*> pessoasFisicas;
        map<string, PessoaJuridica*> pessoasJuridicas;
        map<string, Loja*> lojas;
        map<string, Casal*> casais;
        map<string, Compra*> compras;
        map<string, Festa*> festas;
        map<string, Tarefa*> tarefas;
        map<string, NovoLar*> novosLares;
        map<string, Casamento*> casamentos;

    public:
        Cadastro();
        void addPessoaFisica(string id, PessoaFisica& pessoa);
        void addPessoaJuridica(string id, PessoaJuridica& pessoa);
        void addLoja(string id, Loja& loja);
        void addCasal(string id, Casal& casal);
        void addCompra(string id, Compra& compra);
        void addFesta(string id, Festa& festa);
        void addTarefa(string id, Tarefa& tarefa);
        void addNovoLar(string id, NovoLar& novoLar);
        void addCasamento(string id, Casamento& casamento);

        PessoaFisica* getPessoaFisica(string id);
        PessoaJuridica* getPessoaJuridica(string id);
        Casal* getCasal(string id);
        Casal* getCasalPorCpfs(string cpf1, string cpf2);
        map<string, Casal*> getMapCasais();
        map<string, Casamento*> getMapCasamentos();
        map<string, Festa*> getMapFestas();
        map<string, Tarefa*> getMapTarefas();
        map<string, NovoLar*> getMapNovosLares();
        map<string, Compra*> getMapCompras();
        map<string, Loja*> getMapLojas();
        map<string, PessoaFisica*> getMapPessoasFisicas();
        map<string, PessoaJuridica*> getMapPessoasJuridicas();

        bool verificaIdPessoas(string id);
        bool verificaIdLares(string id);
        bool verificaIdCasamentos(string id);
        bool verificaIdTarefas(string id);
        bool verificaIdCompras(string id);
        bool verificaIdFestas(string id);
        bool verificaIdLojas(string id);
        bool verificaCNPJ(string cnpj);

        void cadastraPessoas(vector <string> dados);
        void cadastraLares(vector <string> dados);
        void cadastraCasamentos(vector <string> dados);
        void cadastraTarefas(vector <string> dados);
        void cadastraCompras(vector <string> dados);
        void cadastraFestas(vector <string> dados);


        void liberarMemoria();
        void liberarPessoasFisicas();
        void liberarPessoasJuridicas();
        void liberarCasais();
        void liberarCasamentos();
        void liberarTarefas();
        void liberarCompras();
        void liberarFestas();
        void liberarLojas();
        void liberarNovosLares();
        ~Cadastro();
};