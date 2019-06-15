#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>
#include<sstream>

using namespace std;


class Node{
	private:
		string full_name; // chave
		string tel; // inf. satelite
		string address; // inf. satelite
		unsigned int years; // inf. satelite
		Node *next; // ref. p/ no seguinte

	public:
 // Construtor
		Node(string n,string tel,string ad,unsigned int y);
	
 // Getter methods...
		Node* getNext();
		string getName();
 // Setter methods...
 
		void setNext(Node *n);
 };
 
 #endif
