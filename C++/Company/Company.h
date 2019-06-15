#ifndef COMPANY_H
#define COMPANY_H

#include<iostream>
#include<sstream>
#include<string>
#include "Employee.h"
using namespace std;

class Company{
	
	private:
		string name;
		long int CNPJ;
		int numEmp;
		Employee *empr;
		
	public:
		Company(string n, long int cnp);
		~Company();
		string getName();
		long int getCNPJ();
		void setName(string n);
		void setCNPJ(long int c);
		void printEmpl();
		void setEmp();
		
		
};















#endif
