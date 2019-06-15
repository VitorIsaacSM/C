#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<string>
#include<sstream>
#include "node.h"

using namespace std;

class List{
private:
	unsigned int size;
	Node *head;
public:
	List();
	// Getter methods...
	Node* searchNode(string name);
	unsigned int getSize();
	Node* getHead();
	void printList();
	// Setter List methods...
	void insertLast(Node *n);
	void insertFirst(Node *n);
	Node* removeLast();
	Node* removeFirst();
};




#endif
