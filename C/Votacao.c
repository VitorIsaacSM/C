// Exercicio46
// Vitor Isaac Sitton Maia
/*Faca um programa que calcule e mostre:
• o total de votos para cada candidato;
• o total de votos nulos;
• o total de votos em branco;
• a porcentagem de votos nulos sobre o total de votos; e
• a porcentagem de votos em branco sobre o total de votos.
Para finalizar o conjunto de votos, tem-se o valor zero e, para codigos invalidos, o programa devera assumir que 
o voto e nulo. Caso nenhuma voto seja fornecido, nao imprima nada. 
*/
// 16/04/18
#include<stdio.h>

int main(void){
	
	int n = 999;
	int cand1 = 0,cand2 = 0,cand3 = 0,cand4 = 0,null = 0,branco = 0;
	float total =0;
	double Pnull,Pbranco;
	
	
	while(n!=0){
		
		scanf("%d",&n);
		
		if(n==1){
			cand1++; total++;
		}
		
		else if(n==2){
			cand2++; total++;
		}
		
			else if(n==3){
				cand3++; total++;
			}
			
				else if(n==4){
					cand4++; total++;
				}
				
					else if(n==6){
						branco++; total++;
					}
						else{
							if((n==5)||(n!=0)){
								null++; total++;
							}
						}
				
		
	}
	
	if(null>0){
		Pnull = null/total;
	}
	
	else{
		Pnull = 0;
	}
	
	
	
	if(branco>0){
		Pbranco = branco/total;
	}
	
	else{
		Pbranco = 0;
	}
	
	
	
	printf("%d  %d  %d  %d  %d  %d %.4lf  %.4lf",cand1,cand2,cand3,cand4,null,branco,Pnull,Pbranco);
	
}
