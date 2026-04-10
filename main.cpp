#include <iostream>
#include <vector>
#include <cctype> // para a verificação dos erros, is digit posterior

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
		
		// limpando o buffer do teclado, igual fflush(stdin) de C
		cin.ignore();
		
		cout << "Responsavel: ";
		// os.variavel significa ler a linha digitada
		getline(cin, os.responsavel);
		
		cout << "Codigo da Empresa: ";
		getline(cin, os.codigoempresa);
		
		cout << "Nome do Contato: ";
		getline(cin, os.nomecontato);
		
		cout << "Telefone para contato: ";
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
		
		cout << "Digite a data de abertura da ordem: (dd/mm/aaaa) ";
		getline(cin, os.dataabertura);
		
		cout << "Digite a previsao de data de entrega: (dd/mm/aaaa) ";
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
	
	// Função para deletar as ordens
	void deletarordem(){
		int id;
		cout << "Digite a ID para deletar\n";
		cin >> id;
		
		//percorre o vetor da lista
		for (int i = 0; i < lista.size(); i++){
			// se o valor de id da posição de lista for igual a id solicitada para digitar
			if (lista[i].id == id){
				// remove item da posição i
				lista.erase(lista.begin() + i);
				cout << "\nOrdem Excluida";
				return;
			}
		}
	}
	
void editarcampo (string &campo){
	string novovalor;
	cout << "Digite o novo valor\n";
	cin.ignore();
	getline(cin, novovalor);
	
	campo = novovalor;
}	
	
	
	void editarordem(){
		int id, edit; 
		cout << "Digite a ID para editar\n";
		cin >> id;
		
		cin.ignore();
		
		// percorre o vetor da lista e tentar a achar a id da ordem para editar
		for (int i = 0; i < lista.size(); i++){
			if (lista[i].id == id){
				// menu para uma edição unica
				do {
				
				cout << "Qual campo deseja editar?" << endl;
				cout << "1 - Responsavel: " << endl;
				cout << "2 - Codigo da empresa: " << endl;
				cout << "3 - Contato: " << endl;
				cout << "4 - Telefone: " << endl;
				cout << "5 - Email: " << endl;
				cout << "6 - Tipo de Serviço: " << endl;
				cout << "7 - Descricao: " << endl;
				cout << "8 - Observacoes: "  << endl;
				cout << "9 - Forma de Pagamento: " << endl;
				cout << "10 - Data de Entrega: " << endl;
				cout << "0 - Sair" << endl;
				cin >> edit;
				
				switch(edit){
					case 1: editarcampo(lista[i].responsavel); break;
					case 2: editarcampo(lista[i].codigoempresa); break;
					case 3: editarcampo(lista[i].nomecontato); break;
					case 4: editarcampo(lista[i].telefone); break;
					case 5: editarcampo(lista[i].email); break;
					case 6: editarcampo(lista[i].tiposervico); break;
					case 7: editarcampo(lista[i].descricao); break;
					case 8: editarcampo(lista[i].observacoes); break;
					case 9: editarcampo(lista[i].formapagamento); break;
					case 10: editarcampo(lista[i].dataentrega); break;
					
						
				}
			} while (edit != 0);
		}
	}
}


// Função Principal para chamar as funções	
int main() {
    int opcao;

    do {
        cout << "\n1 - Criar Ordens\n";
        cout << "2 - Listar Ordens\n";
        cout << "3 - Deletar Ordens\n";
        cout << "4 - Editar Ordens\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1: criarordem(); break;
            case 2: listarordem(); break;
			case 3: deletarordem(); break;
			case 4: editarordem(); break;
        }

    } while(opcao != 0);

    return 0;
}
