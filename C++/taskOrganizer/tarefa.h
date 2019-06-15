#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <list>
#include <iomanip>

// vitor isaac sitton maia

using namespace std;



typedef struct date{
	
	int ano;
	int mes;
	int dia;
	int hora;
	int min;
	
} data;

class tarefa{

	private:
		string titulo;
		string desc;
		data d;
		
	public:
		tarefa(string, string);
		string getTitulo();
		string getDesc();
		int getAno();
		int getMes();
		int getDia();
		int getHora();
		int getMin();
		void printData();
};


//funcoes simples

bool comparaTarefa(tarefa first, tarefa second);

void LimitPrint(list<tarefa> l);

int getInt();

bool isNumeric(char c);


bool checkTarefa(tarefa t);








#endif
