#include "list.h"

List::List(){
	size = 0;
	head = NULL;

}

void List::insertLast(Node *n){
	
	if (size == 0){
		
		head = n;
		size++;
		return;
	}
	
	else{
		
		Node *aux = head;
		
		while (aux->getNext() != NULL){
			
			aux = aux->getNext();

		}
		aux->setNext(n);

	}
	
	size++;

}

void List::insertFirst(Node *n){
	
	if (size == 0){
		
		head = n;
		size++;
		return;
	}
	
	Node* tmp = head;
	
	head = n;
	
	n->setNext(tmp);
	
	size++;
}

Node* List::removeFirst(){
	
	
	if(size == 0){
		
		return NULL;
		
	}
	
	Node *aux = head->getNext();
	Node *tmp = head;
	
	head = aux;
	
	size--;
	
	return tmp;
	
	
}

Node* List::removeLast(){
	
	Node *aux = head;
	Node *tmp;
	
	if(size == 0){
		
		return NULL;
		
	}
	
	if(size == 1){
		
		head = NULL;
		return aux;

	}
	
	
	while(aux->getNext()->getNext() != NULL){
		
		
		aux = aux->getNext();
		
	}
	
	tmp = aux->getNext();
	
	aux->setNext(NULL);
	
	return tmp;
	
	
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
