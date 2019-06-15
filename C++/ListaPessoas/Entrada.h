
// Vitor Isaac Sitton Maia
// 01/09/2018


#ifndef ENTRADA_H
#define ENTRADA_H

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

long long int toInt(string sel);

class Entrada{
	private:
		string full_name; // 
		long long int cpf; // 
		string cadastro; // inf. satelite
		Entrada *next; // aponta para a Entrada seguinte
		Entrada *prev; // aponta para o Entrada aterior



	public:
 // Construtor
		Entrada();
		Entrada(string nome, long long int cpf, string cad);
		~Entrada();
	
 // Getter methods...
		Entrada* getNext(); // retorna a proxima Entrada
		Entrada* getPrev(); // retorna a Entrada anterior
		string getName(); // retorna o nome
		long long int getCpf(); // retorna o valor do cpf
		string getCad(); // retorna o valor do cadastro
		string toString(); // retorna o valor em formato string separando por virgula cada atributo 
		void printData(); // imprime de forma organizada o conteudo 
 // Setter methods...
 
		void setNext(Entrada *n); // altera o valor de next
		void setPrev(Entrada *n); // altera o valor de prev
		void setNewCpf();
 };
 

 
 #endif
