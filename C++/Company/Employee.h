#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<sstream>
#include<string>

using namespace std;


class Employee {

	private:
		string name;
		float salary;
		string adms;
	
	public:
		Employee();
		~Employee();
		string getName();
		string getAdms();
		float getSal();
		void setName(string newName);
		void setSalary(float newSal);
		string toString();
	
};

#endif
