#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include "tarefa.h"

// vitor isaac sitton maia


// falta implementar no input do limite da tarefa
// uma funcao que veja se o tempo limite da tarefa faz sentido
// considerando o data e o tempo atual

using namespace std;

int main(){

	int seletor = 0;
	string inputTitulo;
	string inputDesc;
	

	list<tarefa> lista;
	
	do{
	
		cout << "(1) Adicionar uma tarefa" << endl;
		cout << "(2) Remover uma tarefa" << endl;
		cout << "(3) Listar tarefas (Ordem de atribuicao)" << endl;
		cout << "(4) Listar tarefas (Ordem de limite)" << endl;
		cout << "(5) Sair" << endl;
		
		seletor = getInt(); 
		
		// foi necessario adicionar chaves nos cases pois acontecia um erro onde nao era possivel criar um iterador dentro do case
		switch(seletor){
			case 1:{
				cout << "Digite o titulo da tarefa: " << endl;
				getline(cin, inputTitulo);
				cout << "Digite uma descricao para a tarefa: " << endl;
				getline(cin, inputDesc);
				lista.push_back(tarefa(inputTitulo,inputDesc));
				if(checkTarefa(lista.back())){				
					cout << endl << "Tarefa adicionada com sucesso! " << endl << endl;				
				}
				else{
					cout << endl << "Erro, entrada invalida. Nao foi possivel adicionar a tarefa " << endl << endl;
					lista.pop_back();
				}
				
				break;
				
			}
				
			case 2:{				
				bool rmv = false; // booleana para checar se a remocao foi realizada com sucesso			
				cout << "Tarefas: " << endl;				
				// itera pela lista
				for( auto& i : lista){
					cout << " - " << i.getTitulo() << endl;
				}
							
				cout << endl << "Digite o titulo da tarefa que deseja remover: " << endl;
				getline(cin, inputTitulo);
				
				list<tarefa>::iterator it;
				
				for(it = lista.begin(); it != lista.end();){
					if(inputTitulo == it->getTitulo()){
						it = lista.erase(it);
						rmv = true;
						break;
					}	
					else{
						it++;
					}
				}
				
				if(rmv){
					cout << "Tarefa removida com sucesso " << endl << endl;
					break;
				}
				
				cout << "Tarefa nao encontrada..." << endl << endl;
				break;
			}
			
			case 3:{
			
				if(lista.empty()){
					cout << endl << "Lista vazia" << endl << endl;
					break;
				}
			
				for( auto& i : lista){
					
					cout << endl << "- Titulo: " << i.getTitulo() << endl;
					cout << "- Descricao: " << i.getDesc() << endl;
					cout << "- Limite: ";  i.printData(); cout << endl;
			
				}
				break;
			}
			
			case 4:
			{		
			
				if(lista.empty()){
					cout << endl << "Lista vazia" << endl << endl;
					break;
				}
				
				LimitPrint(lista);
				break;						
			}
			
		}
		
	
	} while(seletor != 5);
	

}
