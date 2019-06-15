#include "Employee.h"

Employee::Employee(){
	
	cout << "digite o nome do funcionario: " << endl;
	getline(cin,name);
	cout << "digite o salario: " << endl;
	cin >> salary;
	cin.get();
	cout << "digite a data de admissao: " << endl;
	getline(cin,adms);
	
}

Employee::~Employee(){
	

}

void Employee::setName(string newName){
	
	name = newName;
	
}

void Employee::setSalary(float newSal){
	
	salary = newSal;
	
}


string Employee::toString(){
	
	stringstream a;
	
	a << "nome: " << this->getName() << " , data de admissao: " << this->getAdms() << " , salario: " << this->getSal() << endl;
	
	return a.str();
	
}

string Employee::getName(){
	
	return name;
	
}

string Employee::getAdms(){
	
	return adms;
	
}

float Employee::getSal(){
	
	return salary;
	
}

