#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

	class Ordemservico{
	  public :
		int id;
		string responsavel;
		string codigoempresa;
		string nomecontato;
		string telefone;
		string email;
		string tiposervico;
		string descricao;
		string observacoes;
		string formapagamento;
		string dataabertura;
		string dataentrega;
	};
	
	// declarar vetor dinâmico que armazena os dados de objeto de  Ordemserviço na variavel lista
	vector<Ordemservico> lista;
	//inicializar variavel para contar as ids de serviço
	int contadorID = 1;
	
	void criarordem(){
		//definindo objeto os da classe OrdemServico
		Ordemservico os;
		//iniciando a contagem das IDs
		os.id = contadorID++;
		
		// limpando o buffer do teclado, igual fflush(stdin)
		cin.ignore();
		
		cout << "Responsavel: ";
		// os.variavel significa ler 
		getline(cin, os.responsavel);
		
		cout << "Codigo da Empresa: ";
		getline(cin, os.codigoempresa);
		
		cout << "Nome do Contato";
		getline(cin, os.nomecontato);
		
		cout << "Telefone para contato";
		getline(cin, os.telefone);
		
		cout << "Email: ";
		getline(cin, os.email);
		
		cout << "Tipo de Servico: ";
		getline(cin, os.tiposervico);
		
		cout << "Descricao do Servico: ";
		getline(cin, os.descricao);
		
		cout << "Observacao: ";
		getline(cin, os.observacoes);
		
		cout << "Forma de Pagamento: ";
		getline(cin, os.formapagamento);
		
		cout << "Digite a data de abertura da ordem: ";
		getline(cin, os.dataabertura);
		
		cout << "Digite a previsao de data de entrega: ";
		getline(cin, os.dataentrega);
		
		// adiciona a ordem no vetor dinamico lista
		lista.push_back(os);
		
		cout << "Ordem Criada!";
		
	}
	
	// Função que lista 
	void listarordem(){
		//Percorre o vetor dinamico da variavel lista dentre os objetos os de ordem de serviço
		for (auto os : lista){
			cout << "\n ID: " << os.id << endl;
			cout << "Responsavel: " << os.responsavel << endl;
			cout << "Codigo da empresa: " << os.codigoempresa << endl;
			cout << "Contato: " << os.nomecontato << endl;
			cout << "Telefone: " << os.telefone << endl;
			cout << "Email: " << os.email << endl;
			cout << "Tipo de Serviço: " << os.tiposervico << endl;
			cout << "Descricaoo: " << os.descricao << endl;
			cout << "Observacoes: " << os.observacoes << endl;
			cout << "Forma de Pagamento: " << os.formapagamento << endl;
			cout << "Data de Abertura: " << os.dataabertura << endl;
			cout << "Data de Entrega: " << os.dataentrega << endl;
		}
	}
	
// Função Principal para chamar as funções	
int main() {
    int opcao;

    do {
        cout << "\n1 - Criar Ordens\n";
        cout << "2 - Listar Ordens\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1: criarordem(); break;
            case 2: listarordem(); break;
        }

    } while(opcao != 0);

    return 0;
}
