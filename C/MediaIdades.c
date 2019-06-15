// Exercicio41
// Vitor Isaac Sitton Maia
/*Faca um programa que receba varias idades, calcule e mostre a media das idades digitadas. Finalize digitando 
idade igual a zero. Caso nenhuma idade seja fornecida, nao imprima nada.
*/
// 16/04/18
#include<stdio.h>


int main(void){
	int idade=99,counter = 0;
	double media = 0;
	
	
	while(idade!= 0){
		scanf("%d",&idade);
		
		if(idade!=0){
			counter++;
			media = media + idade;
			
		}
		
		else{
			
			if(counter > 0){
				media = media/counter;
				printf("%.4lf",media);
			}
			
			
		}
		
	}
	
	
	
	
	
}
