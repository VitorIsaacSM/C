#include"Node.h"

Node::Node(string n,string tel,string ad,unsigned int y){
	
	full_name = n;
	this->tel = tel;
	address = ad;
	years = y;
	next = NULL;
	
}

Node* Node::getNext(){
	
	
		return next;
	
}
	
void Node::setNext(Node *n){
	
	
	
	next = n;
	

	
}

string Node::getName(){
	
	
	return full_name;
	
	}
