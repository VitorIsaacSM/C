// Exercicio32
// Vitor Isaac Sitton Maia
/*Faca um programa que receba a idade, a altura e o peso de cinco pessoas, calcule e mostre:
• a quantidade de pessoas com idade superior a 50 anos;
• a media das alturas das pessoas com idade entre 10 e 20 anos; 
• a porcentagem de pessoas com peso inferior a 40 kg entre todas as analisadas.
*/
// 16/04/18

#include<stdio.h>

int main(void){
	
	int age;//idade
	double h;
	double w;
	int counter1 = 1,counterP50 = 0,counterMedia = 0,counterW = 0;
	double media = 0,perPeso;
	

	
	while(counter1<=5){
		scanf("%d %lf %lf",&age,&h,&w);
		
		if(age>50)
			counterP50++;
		
		if((age>10)&&(age<20)){
			media = media + h;
			counterMedia++;
		}
		
		if(w<40){
			counterW++;
		}
		
		
		
		counter1++;
	}
	if(counterMedia > 0){
	
	media = media/counterMedia;
}
	
	perPeso = counterW/5.0;

	printf("%d %.4lf %.4lf",counterP50,media,perPeso);
	
	
	
	return 0;
}
