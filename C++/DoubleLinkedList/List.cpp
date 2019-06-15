#include "List.h"

List::List(){
	size = 0;
	head = NULL;
	tail = NULL;

}

void List::insertLast(Node *n){
	
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

void List::insertFirst(Node *n){
	
	if (size == 0){
		
		head = n;
		tail = n;
		size++;
		return;

	}
	
	else{
		
		head->setPrev(n);
		n->setNext(head);
		head = n;
		
	}
	
	size++;
}

Node* List::removeFirst(){
	
	Node *aux = head;
	Node *tmp;
	
	if(size == 0){
		
		return NULL;
		
	}
	
	else if(size == 1){
		
		head = NULL;
		tail = NULL;
		return aux;
		
	}
	
	else{
		
		tmp = aux->getNext();
		tmp->setPrev(NULL);
		head = tmp;
		size--;
		return aux;
		
		
	}
	
	
}

Node* List::removeLast(){
	
	Node *aux = tail;
	Node *tmp;
	
	if(size == 0){
		
		return NULL;
		
	}
	
	else if(size == 1){
		
		tail = NULL;
		head = NULL;
		return aux;

	}
	
	else{
		
		tmp = aux->getPrev();
		tmp->setNext(NULL);
		tail = tmp;
		size--;
		return aux;
		
		
	}
	
}

Node* List::searchNode(string name){
	
		Node *aux = head;
		
		while (aux->getName() != name){
			
			aux = aux->getNext();
			
		}
		
		if(aux->getName() == name){
			
			return aux;
			
		}
		
		cout << "nome nao encontrado" << endl;
		return NULL;
	
	}

unsigned int List::getSize(){
	
	
	return this->size;
	
	
	}

Node* List::getHead(){
	
	
	return head;
	
	}
	
Node* List::getTail(){
	
	
	return tail;
	
	}

void List::printList(){
	
	if(size == 0){
		cout <<"lista vazia " << endl;
		return;
		
	}
		
	Node *aux = head;
		
	while(aux->getNext() != NULL){
		
	cout << aux->getName() << endl;
	
	aux = aux->getNext();
			
	}
		
	cout << aux->getName() << endl;
	
	
}

void List::cat(List *n){

	

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
	
		this->tail->setNext(n->head);
		n->head->setPrev(this->tail);
		
		this->tail = n->getTail();
		n->setHead(this->getHead());
		delete(n);
	}


}

void List::setHead(Node *n){

	this->head = n;

}

List::~List(){
	
}

void List::insert(Node *n,int pos){
	
	if((this->size == 0) || (pos <= 1)){
		
		this->insertFirst(n);
		return;
		
	}
	else if(pos > this->size){
		
		this->insertLast(n);
		return;
		
	}
	
	else{
		
		Node *aux = head;
		
		for(int i=1; i!=pos; i++){
			
			aux = aux->getNext();
			
		}
		
		n->setNext(aux);
		n->setPrev(aux->getPrev());
		aux->setPrev(n);
		aux = n->getPrev();
		aux->setNext(n);
		return;
	}
	
	
}


