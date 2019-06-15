// Exercicio02
// Vitor Isaac Sitton Maia
// Faca um programa que leia um valor N inteiro e positivo. Calcule e mostre o valor de E, conforme a formula a seguir:
// 13/04/18

#include<stdio.h>


int main(void){
	
	int N,n1=0,n3;
	double soma = 1,n2=1;
	
	
	scanf("%d",&N);
	
	n3 = 1;
	
	while(n1<N){
		
		
		n2 = n2 * n3;
		n3 = n3+1;
		
		soma = soma + 1.0/(n2);
		
		n1++;
		
	}
	
	printf("%.4lf",soma);

	return 0;
}

