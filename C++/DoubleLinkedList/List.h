#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<string>
#include<sstream>
#include "Node.h"

using namespace std;

class List{
private:
	unsigned int size;
	Node *head;
	Node *tail;
public:
	List();
	~List();
	// Getter methods...
	Node* searchNode(string name);
	unsigned int getSize();
	Node* getHead();
	Node* getTail();
	void printList();
	// Setter List methods...
	void insertLast(Node *n);
	void insertFirst(Node *n);
	Node* removeLast();
	Node* removeFirst();
	void setHead(Node *n);
	
	// concatenate
	void cat(List *n);
	
	//insert
	void insert(Node *n,int pos);
};




#endif
