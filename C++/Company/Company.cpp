#include "Company.h"

Company::Company(string n, long int cnp){
	
	this->name = n;
	CNPJ = cnp;
	
	cout << "quantos funcionarios tem a empresa? " << endl;
	cin >> numEmp;
	cin.get();
	
	empr = new Employee[numEmp];
	
	
}

void Company::setEmp(){
	
	for(int i = 0; i < numEmp ; i++){
		
		Employee a();
		
		//empr[i] = Employee();
		cout << i << endl;
		
	}
	
}

Company::~Company(){
	
	if(empr = NULL){
		return;
	}
	
	free(empr);
	
}

string Company::getName(){
	
	
	
	return name;
	
}

long int Company::getCNPJ(){
	
	return CNPJ;
	
}

void Company::setName(string n){
	
	name = n;
	
}

void Company::setCNPJ(long int c){
	
	CNPJ = c;
	
}

void Company::printEmpl(){
	
	
	int j;
	
	cout << endl;
	
	for(j = 0; j < numEmp; j++){
		
		cout << empr[j].toString() << endl;
		
		
	}
	
	
}








