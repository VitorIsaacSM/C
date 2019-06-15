
// Vitor Isaac Sitton Maia
// 01/09/2018

#include "List.h"


using namespace std;

int main(){
	
	Entrada *n; // ponteiro que recebe o retorno das funcoes
	
	long long int cpf; // valor de cpf digitado pelo usuario para funcoes de busca e delete
	string Scpf;
	
	// valor da opcao do menu , passado como string e verificado
	// para certificar-se de que e um valor inteiro
	int s;
	string selecao;

	List *lista = new List(); // criacao da lista
	
	do{
		
		cout << endl;
		cout << "(1) : Inserir       : " << endl;
		cout << "(2) : Procurar      : " << endl;
		cout << "(3) : Deletar       : " << endl;
		cout << "(4) : Salvar Lista  : " << endl;
		cout << "(5) : Abrir Lista   : " << endl;
		cout << "(6) : Imprimir      : " << endl;
		cout << "(7) : Organizar     : " << endl;
		cout << "(8) : Sair          : " << endl;
		
		getline(cin,selecao);
		s = toInt(selecao);
		
			switch(s){
			
				case 1:				
					lista->insertLast(new Entrada());
					cout << endl << "Cadastro realizdo com sucesso! " << endl << endl;
					break;
					
				case 2:					
					cout << "digite o CPF da pessoa que voce procura: " << endl;
					getline(cin,Scpf); // transforma o valor dado em inteiro nao aceitando outras coisas
					cpf = toInt(Scpf);
					
					n = lista->searchEntrada(cpf);
					
					if(n != NULL){
						
						n->printData();
						
					}
					
					break;
					
				case 3:
					cout << "digite o CPF da pessoa que voce deseja deletar da lista: " << endl;
					getline(cin,Scpf); // transforma o valor dado em inteiro nao aceitando outras coisas
					cpf = toInt(Scpf);
					
					n = lista->del(cpf);
					
					
					if(n != NULL){
						
						cout << endl << "Dados da pessoa que foi deletada: " << endl;
						n->printData();
						
						// OBS: a funcao retorna a "entrada" que foi removida
						// porem ela é simplesmente imprimida na tela e descartada
						// pois nao esta especificado o que a funçao de busca deve
						// fazer. 
				
						
					}
				
					break;
					
					
				case 4:
					lista->save();
					break;
					
				case 5:
					lista->load();
					break;
					
				case 6:
					lista->printList();
					break;
					
				case 7:
					lista->sort();
					break;
			
			}
		
		
		
	}while(s != 8);
	
	
	
	
	return 0;
	
	
}




	
	

