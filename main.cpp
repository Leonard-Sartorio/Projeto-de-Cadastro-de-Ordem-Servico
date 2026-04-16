#include <iostream>
#include <vector>

using namespace std;

// Enum de setores
enum Setor 
{
 Contabilidade,
 Fiscal,
 DepartamentoPessoal,
 Legalizacao,
 Administrativo
};

	class Ordemservico{
	  public :
		int id;
		Setor responsavel; // agora usando enum
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
		float valorservico;
		float desconto;
	};
	
	// declarar vetor dinâmico que armazena os dados de objeto de  Ordemserviço na variavel lista
	vector<Ordemservico> lista;
	//inicializar variavel para contar as ids de serviço
	int contadorID = 1;

	float lerfloat (string mensagem){
		float valor;

		while (true) {
			cout << mensagem;
			cin >> valor;

			if(cin.fail() || valor < 0){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entrada invalida! Digite um numero positivo.\n";
			} else {
				cin.ignore(1000, '\n');
				return valor;
			}
		}
	}
	
	// função que cria ordem
	void criarordem(){
		//definindo objeto os da classe OrdemServico
		Ordemservico os;
		//iniciando a contagem das IDs
		os.id = contadorID++;
		
		cin.ignore();
		
		// seleção do setor (responsavel)
		int setor;
		do {
			cout << "Responsavel (Setor):\n";
			cout << "0 - Contabilidade\n";
			cout << "1 - Fiscal\n";
			cout << "2 - Departamento Pessoal\n";
			cout << "3 - Legalizacao\n";
			cout << "4 - Administrativo\n";
			cout << "Escolha: ";
			cin >> setor;

			if(cin.fail() || setor < 0 || setor > 4){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Opcao invalida!\n";
			}

		} while(cin.fail() || setor < 0 || setor > 4);

		os.responsavel = (Setor)setor;
		cin.ignore();
		
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
		
		os.valorservico = lerfloat("Digite o valor do servico em R$: ");
		
		do {
			os.desconto = lerfloat("Digite o desconto (se houver) em R$: ");
			
			if (os.desconto > os.valorservico){	
				cout << "Desconto nao pode ser maior que o valor de servico!\n";	
			}
			
		} while (os.desconto > os.valorservico);
		
		// adiciona a ordem no vetor dinamico lista
		lista.push_back(os);
		
		cout << "\n\nOrdem Criada!";
		
	}
	
	// Função que lista 
	void listarordem(){
		
		//função que define da biblioteca vector que define quando um vetor vazio
		if (lista.empty()){
			cout << "\nNao ha ordens criadas!\n";
			return;
		}

		string setores[] = {
			"Contabilidade",
			"Fiscal",
			"Departamento Pessoal",
			"Legalizacao",
			"Administrativo"
		};
		
		//Percorre o vetor dinamico da variavel lista dentre os objetos os de ordem de serviço
		for (auto os : lista){
			cout << "\nID: " << os.id << endl;
			cout << "Responsavel: " << setores[os.responsavel] << endl;
			cout << "Codigo da empresa: " << os.codigoempresa << endl;
			cout << "Contato: " << os.nomecontato << endl;
			cout << "Telefone: " << os.telefone << endl;
			cout << "Email: " << os.email << endl;
			cout << "Tipo de Servico: " << os.tiposervico << endl;
			cout << "Descricao: " << os.descricao << endl;
			cout << "Observacoes: " << os.observacoes << endl;
			cout << "Forma de Pagamento: " << os.formapagamento << endl;
			cout << "Data de Abertura: " << os.dataabertura << endl;
			cout << "Data de Entrega: " << os.dataentrega << endl;
			cout << "Valor do Servico: R$ " << os.valorservico - os.desconto << endl;
		}
	}
	
	// Função para deletar as ordens
	void deletarordem(){
		
		//Verificação para se caso um usuario querer usar um crud sem ter nenhuma id
		if (lista.empty()){
			cout << "\nNao ha ordens criadas!\n";
			return;
		}
		
		int id;
		
		while (true) {
			cout << "Digite a ID para deletar\n";
			cin >> id;
			
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nEntrada Invalida! Tente Novamente...\n";
			} else {
				break;
			}
		}
		
		for (int i = 0; i < lista.size(); i++){
			if (lista[i].id == id){
				lista.erase(lista.begin() + i);
				cout << "\nOrdem Excluida!\n";
				return;
			}
		}
		
		cout << "\nOrdem nao encontrada!\n";
	}
	
	void editarcampo (string &campo){
		string novovalor;
		cout << "Digite o novo valor\n";
		getline(cin, novovalor);
		
		campo = novovalor;
	}	

	void editarcamponumerico (float &campo){
		float novovalor;
		
		while (true){
			cout << "Digite o novo valor\n";
			cin >> novovalor;
			
			if(cin.fail() || novovalor < 0){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nEntrada Invalida! Tente Novamente\n";
			} else {
				cin.ignore(1000, '\n');
				campo = novovalor;
				cout << "\nCampo Editado!";
				return;
			}
		}
	}
	
	void editarordem(){
		
		if (lista.empty()){
			cout << "\nNao ha ordens criadas!\n";
			return;
		}
		
		int id, edit; 
		cout << "Digite a ID para editar\n";
		cin >> id;
		
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nEntrada Invalida! Tente Novamente\n";
			return;
		}
		
		cin.ignore();
		
		for (int i = 0; i < lista.size(); i++){
			if (lista[i].id == id){
				do {
				
				cout << "\nQual campo deseja editar?" << endl;
				cout << "1 - Responsavel: " << endl;
				cout << "2 - Codigo da empresa: " << endl;
				cout << "3 - Contato: " << endl;
				cout << "4 - Telefone: " << endl;
				cout << "5 - Email: " << endl;
				cout << "6 - Tipo de Servico: " << endl;
				cout << "7 - Descricao: " << endl;
				cout << "8 - Observacoes: "  << endl;
				cout << "9 - Forma de Pagamento: " << endl;
				cout << "10 - Data de Entrega: " << endl;
				cout << "11 - Valor de Servico: " << endl;
				cout << "12 - Valor Desconto: " << endl;
				cout << "0 - Finalizar Edicao" << endl;
				cin >> edit;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\nEntrada Invalida! Tente Novamente\n";
					continue;
				}
				
				if (edit < 0 || edit > 12){
					cout << "\nOpcao Invalida! Tente Novamente!!!\n";
					continue;
				}
				
				cin.ignore();
				
				switch(edit){
					case 2: editarcampo(lista[i].codigoempresa); break;
					case 3: editarcampo(lista[i].nomecontato); break;
					case 4: editarcampo(lista[i].telefone); break;
					case 5: editarcampo(lista[i].email); break;
					case 6: editarcampo(lista[i].tiposervico); break;
					case 7: editarcampo(lista[i].descricao); break;
					case 8: editarcampo(lista[i].observacoes); break;
					case 9: editarcampo(lista[i].formapagamento); break;
					case 10: editarcampo(lista[i].dataentrega); break;
					case 11: editarcamponumerico(lista[i].valorservico); break;
					case 12: editarcamponumerico(lista[i].desconto); break;
				}
			} while (edit != 0);
			
			return;
		}
	}
	
	cout << "\nOrdem nao encontrada!\n";
}

// Função Principal para chamar as funções
int main() {
    int opcao;

    do {
    	cout << "\nSistema de Cadastro de Ordem\n";
        cout << "1 - Criar Ordens\n";
        cout << "2 - Listar Ordens\n";
        cout << "3 - Deletar Ordens\n";
        cout << "4 - Editar Ordens\n";
        cout << "0 - Sair\n";
        cout << "\nEscolha: ";
        cin >> opcao;
        
        //verificação para nao aceitar letras
        if(cin.fail()){
        	cin.clear();
			cin.ignore(1000, '\n');
        	cout << "\nEntrada Invalida! Tente Novamente\n";
        	opcao = -1;
        	continue;
		}

        switch(opcao) {
            case 1: criarordem(); break;
            case 2: listarordem(); break;
			case 3: deletarordem(); break;
			case 4: editarordem(); break;
			case 0: cout << "\nSaindo..."; break;
			default: 
			 cout << "\nNumero Invalido Digite novamente...\n" << endl;
		}

    } while(opcao != 0);

    return 0;
}