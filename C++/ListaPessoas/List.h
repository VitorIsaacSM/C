
// Vitor Isaac Sitton Maia
// 01/09/2018

#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "Entrada.h"

using namespace std;

class List{
private:
	unsigned int size;
	Entrada *head;
	Entrada *tail;
public:

	//constructor and destructor
	List();
	~List();
	
	// Getter methods
	Entrada* searchEntrada(long long int cpf);
	unsigned int getSize();
	Entrada* getHead();
	Entrada* getTail();
	void printList();
	void checkCpf(Entrada *n); // verifica se o cpf é valido (se ele ainda nao existe)
	void masterCheckCpf(); // checa todos os cpfs
	
	// Setter methods
	void insertLast(Entrada *n);
	Entrada* removeLast();
	Entrada* removeFirst();
	void setHead(Entrada *n);
	
	// concatenate
	void cat(List *n);
	
	
	//delete
	Entrada* del(long long int cpf); 
	
	//salva a lista em um arquivo csv
	void save();
	
	//le um arquivo csv e o transforma em uma lista 
	void load();
	
	//reseta a lista apagando tudo o que ela contem
	void reset();
	
	//organiza a lista em ordem alfabetica
	void sort();
};




#endif
