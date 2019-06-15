
// Vitor Isaac Sitton Maia
// 01/09/2018

#include "List.h"


// constructor
List::List(){
	size = 0;
	head = NULL;
	tail = NULL;

}

// destructor
List::~List(){
	
}

// getter methods
unsigned int List::getSize(){
	
	return this->size;

} 

Entrada* List::getHead(){
	
	return this->head;
	
} 

Entrada* List::getTail(){
	
	
	return tail;
	
} 

Entrada* List::searchEntrada(long long int cpf){
	
		// procura por um cpf , e , se encontrar retorna o objeto que contem o cpf
	
		Entrada *aux = head;
		
		if(size == 0){
		
			cout << "lista vazia. " << endl << endl;
			return NULL;
		
		}	
		
		for(int i = 0; i<size; i++){
			
			if(aux->getCpf() == cpf){
			
				return aux;
			
			}
			
			aux = aux->getNext();
			
		}
		
		cout << "Nao foi encontrado alguem com este cpf." << endl << endl;
		return NULL;
	
}


// setter methods

void List::insertLast(Entrada *n){
	
	checkCpf(n);
	
	if (size == 0){
		
		head = n;
		tail = n;
		size++;
		return;
	}
	
	else{
		
		tail->setNext(n);
		n->setPrev(tail);
		tail = n;

	}
	
	size++;

}

Entrada* List::removeFirst(){
	
	Entrada *aux = head;
	Entrada *tmp;
	
	if(size == 0){
		
		return NULL;
		
	}
	
	else if(size == 1){
		
		this->head = NULL;
		this->tail = NULL;
		
		
		aux->setNext(NULL);
		aux->setPrev(NULL);
		
		return aux;
		
	}
	
	else{
		
		tmp = aux->getNext();
		tmp->setPrev(NULL);
		head = tmp;
		
		aux->setNext(NULL);
		aux->setPrev(NULL);
		
		return aux;
		
		
	}
	
	
}

Entrada* List::removeLast(){
	
	Entrada *aux = tail;
	Entrada *tmp;
	
	if(size == 0){
		
		return NULL;
		
	}
	
	else if(size == 1){
		
		tail = NULL;
		head = NULL;
		
		
		aux->setNext(NULL);
		aux->setPrev(NULL);
		
		return aux;

	}
	
	else{
		
		tmp = aux->getPrev();
		tmp->setNext(NULL);
		tail = tmp;
		
		
		aux->setNext(NULL);
		aux->setPrev(NULL);
		
		return aux;
		
		
	}
	
} 

void List::setHead(Entrada *n){

	this->head = n;

} 

void List::reset(){
	
	// reseta a lista
	
	head = NULL;
	tail = NULL;
	size = 0;
	
	
}

Entrada* List::del(long long int cpf){
	
	// procura por um cpf na lista , e se achar deleta o objeto que o contem

	Entrada *aux = this->head;
	Entrada *prev;
	Entrada *next;
	
	if(size == 0){
		
		cout << "lista vazia, nao ha o que remover. " << endl << endl;
		return NULL;
		
	}
	
	
	for (int i = 0; i<size ; i++){
		
		if(aux->getCpf() == cpf)
			break;
		else	
			aux = aux->getNext();
		
	}
	
	if(aux == NULL){
		
		cout << "Nao foi encontrado alguem com este CPF." << endl << endl;
		return NULL;
		
	}
	
	else if(aux == head){
		
		this->removeFirst();
		
		
	}
	
	else if(aux == tail){
		
		this->removeLast();
		
	}
	
	else{
		
		prev = aux->getPrev(); // Entrada anterior ao que sera deletado
		next = aux->getNext(); // Entrada que vem depois da que sera deletada
		
		prev->setNext(next); 
		next->setPrev(prev);
	
	}
	
	
	
	// altera os ponteiros next e prev da Entrada que foi removida 
	// para que nao tenha mais acesso a lista
	aux->setNext(NULL); 
	aux->setPrev(NULL);
	size--;
	
	return aux;
	
	
}
	

// print 
void List::printList(){
	
	if(size == 0){
		cout << endl << "lista vazia " << endl << endl;
		return;
		
	}
	
	cout << endl << "LISTA:"<< endl << endl;
		
	Entrada *aux = head;
		
	for(int i = 0; i<size ; i++){
		
		cout << "Posicao: " <<  i+1 ;
		aux->printData();
	
		aux = aux->getNext();
	}

	
}

// concatenate
void List::cat(List *n){

	// adiciona uma lista no final da lista atual
	// define o next do tail desta lista como o tail da lista2
	// e o prev do tail da lista2 com o tail desta lista
	// depois define this->tail como o tail da lista2
	// e soma os tamanhos das listas
	

	if(n->getSize()== 0){
	
		delete(n);
		return;
	
	}
	
	else if(this->getSize() == 0){
		
		this->head = n->getHead();
		this->tail = n->getTail();
		this->size = n->getSize();
		delete(n);
		return;
		
	}

	else{
		
		
		this->printList();
		n->printList();
	
		Entrada *tmp = n->getHead();
		
		this->tail->setNext(n->getHead());
		n->getHead()->setPrev(this->tail);
		
		this->tail = n->getTail();
		this->size += n->getSize();
		
		
		
	}

	
	
	
	
	
	

}

// salvar lista atual em um arquivo csv
void List::save(){
	
	string nomeDaLista;  // nome do arquivo que sera dado pelo usuario
	ofstream saida;  // arquivo
	Entrada *aux = head; 
	
	cout << "Digite um nome para o arquivo com as informacoes da lista:" << endl;
	cout << "Nao incluir o tipo do arquivo ( .csv )" << endl;
	getline(cin,nomeDaLista);
	
	nomeDaLista += ".csv"; // adiciona o .csv ao nome do arquivo

	saida.open(nomeDaLista,ios::out); 
	
	for(int i = 0; i<size; i++){
		
		saida << aux->toString(); // a funcao to string retorna o valor de cada Entrada em um formato csv
		
		aux = aux->getNext(); // avança para o proximo
			
	}
	
	saida.close();
	
	cout << endl << "Operacao concluida com sucesso, dados salvos no arquivo " << nomeDaLista << endl << endl;
	
}

// carrega uma lista de um arquivo csv lido
void List::load(){
	
	bool erase = false; // variavel de decisao apagar ou nao apagar(concatenar)
	string nomeDaLista;  // nome do arquivo que sera dado pelo usuario
	ifstream entrada;  // arquivo
	Entrada *aux = head; 
	List *l = new List(); // lista auxiliar para concatenacao
	string nome;    // nome completo
	string sCpf;    // cpf em forma de string
	long long int liCpf; // cpf em forma de inteiro
	string cad;     // cadastro
	
	
	// se o tamanho do arquivo for maior que 0, logo ja existe algo na lista tual
	// portanto o programa pergunta se voce deseja continuar com a operacao, o que
	// resultara na perda das informaçoes que estao na lista atualmente.
	if(size > 0){
		
		string decide;
		
		
		cout << endl;
		cout << "Deseja Apagar a lista atual?" << " (todas as informaçoes serao perdidas)" << endl;
		cout << endl << "Ou concatenar as duas listas? (mantem os dados presentes atualmente)" << endl << endl ;
		
		do{
			//cout << "Digite (sim) para ." << endl;
			//cout << "ou" << endl << "(nao) para cancelar e voltar ao menu" << endl;
			//getline(cin,decide);
			
			cout << "(1) : Apagar " << endl;
			cout << "(2) : Concatenar " << endl;
			cout << "(3) : Cancelar " << endl;
			
			
			cin >> decide;
			cin.get();
			
			if(decide == "1"){
			
				erase = true;
				break;
			
			}
			
			if(decide == "2"){
			
				erase = false;
				break;
			
			}
			
			if(decide == "3"){
				
				cout << endl << "Operacao cancelada. "<< endl;
				return;
				
			}
			
		}while(decide != "1" && decide != "2" && decide != "3");
		
	}
	
	cout << endl << "Digite o nome do arquivo que deseja carregar :" << endl;
	cout << "Nao incluir o tipo do arquivo ( .csv ) :" << endl;
	getline(cin,nomeDaLista); 
	
	nomeDaLista += ".csv"; // adiciona o .csv ao nome do arquivo
	
	entrada.open(nomeDaLista,ios::in);
	
	// verifica se o arquivo foi aberto corretamente
	if( !entrada.is_open() ){
		
		cout << "falha ao abrir arquivo" << endl;
		return;
		
	}
	
	if(erase == true){
		
		this->reset(); //funçao reset apaga a lista atual
		l = this;
	}
		
	while(entrada.good()){
		
		getline(entrada,nome,','); //pega a primeira string ate achar uma virgula
		getline(entrada,sCpf,','); //pega a segunda string ate achar uma virgula
		getline(entrada,cad,'\n'); // pega a terceira string ate achar um \n (nova linha)
		
		// verifica se o cadastro tem um valor aceitavel
		if( cad != "regular" && cad != "irregular"){ 
			
			cout << "ERRO.. O CONTEUDO DO ARQUIVO NAO E VALIDO!" << endl;
			entrada.close();
			return;
			
		}
		
		
		stringstream ssCpf; // cpf em forma de StringStream
		
		ssCpf << sCpf;
		ssCpf >> liCpf; // transforma o valor do cpf de string para inteiro
		
		//verifica mais uma vez se o estado do arquivo.
		//necessario para prevenir que seja adicionado um elemento a mais que nao deveria existir
		if(entrada.good())
			l->insertLast(new Entrada(nome,liCpf,cad));
		
	}
	
	entrada.close(); // fecha o arquivo
	
	if(erase == false){
		
		this->cat(l);
		this->masterCheckCpf();
		
	}
	
	
	cout << endl << "Operacao realizada com sucesso!" << endl << endl;

	
	
}

// verifica se o cpf de uma entrada eh valido
void List::checkCpf(Entrada *n){
	
	//funcao que garante que o CPF tenha um valor valido
	// quando uma Entrada é adicionada o objeto é passado para esta funcao
	// e ela verifica se o valor do CPF digitado ja existe na lista
	// dando uma opcao para o usuario alterar o CPF caso ja exista
	
	
	
	long long int CPF ;
	Entrada *aux = this->head;
	
	while(aux != NULL){
		
		CPF = n->getCpf();
		
		if(CPF == aux->getCpf()){
			
			
			cout << "Ops, CPF invalido .( " << n->getCpf()  <<" ) Este CPF ja existe e esta cadastrado." << aux->getName() << endl;
			n->setNewCpf(); // 
			
			aux = this->head;
			
		}
		
		else{
			
			aux = aux->getNext();
		}
		
		
	}
	
	
}


void List::masterCheckCpf(){
	
	Entrada *aux = tail;
	
	
	
	for (int i = 0; i<this->getSize(); i++){
		
		Entrada *tmp = this->head;
		
		while(tmp != NULL){
			
			if(tmp != aux){
				
				if(tmp->getCpf() == aux->getCpf()){
					
					cout << "Ops, CPF invalido -> " << aux->getCpf()  <<" da pessoa \""<< aux->getName() << "\""<<endl <<"Este CPF ja existe e esta cadastrado no nome de \"" << tmp->getName()<<"\"" << endl;
					cout << "Nao podem existir duas pessoas com o mesmo CPF, portanto sera alterado o CPF de \"" << aux->getName() << "\"" << endl;
					aux->setNewCpf();
					tmp = this->head;
					
					
				}
				
				else{
			
				tmp = tmp->getNext();
				
				}
				
			}
			
			else{
			
				tmp = tmp->getNext();
				
			}
			
		}
		
		aux = aux->getPrev();
		
	}

	
}

// ordena alfabeticamente
void List::sort(){
	
	if(size == 0 || size == 1){
		
		return;
		
	}
	
	
	List *copy = new List(); 		 // cria uma copia da lista atual
	Entrada *menor ;	 			 // ponteiro para o objeto com o menor valor do nome
	Entrada *aux ;           		 //
	
	for(int i = 0; i < this->getSize(); ){
		
		menor = this->getHead();
		aux = menor->getNext();
		
		for(int j = 0; j < this->getSize(); ){
			
			if(aux != NULL){
				
				if(menor->getName() > aux->getName()){
					
					menor = aux;
					aux = aux->getNext();
				}
		
				else{
					aux = aux->getNext();
				}
				
			}
			
			else
				break;
		
		}
		

		aux = this->del(menor->getCpf());
		copy->insertLast(aux);
		
		
	}
	
	this->reset();    // reseta a lista 
	
	for(int i = 0; i < copy->getSize(); ){
		
		aux = copy->getHead();
		aux = copy->del(aux->getCpf());
		this->insertLast(aux);
		
	}
	
	delete(copy);
	
	cout << endl << "Operacao realizada com sucesso!" << endl << "Lista organizada em ordem alfabetica" << endl << endl;

	
}
