// Exercicio01
// Vitor Isaac Sitton Maia
// Faca um programa que leia o ano atual (algum valor maior ou igual a 2005) e determine o salario atual desse funcionario. 
// 13/04/18

#include<stdio.h>


int main(void){
	
	int ano,anoI = 2005;
	double sal = 1000,aumnt = 0.015;
	
	scanf("%d",&ano);
	
	
	while(anoI < ano){
		anoI++;
		
		if(anoI==2006){
			sal = sal+(sal*aumnt);
			
		}
		
		if(anoI != 2006){
			aumnt = aumnt * 2;
			sal = sal+(sal*aumnt);
			
			
		}
		
		
		
	}
	printf("%.4lf",sal);
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
