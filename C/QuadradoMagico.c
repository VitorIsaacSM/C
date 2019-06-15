// Vitor Isaac Sitton Maia

// checa se uma matriz é um "quadrado magico"

#include<stdio.h>


int quadCheck(int vet[30][30],int tam,int max);

int main(void){
	
	int vet[30][30];
	
	int tam;
	int i,j;
	int soma;
	
	scanf("%d",&tam); 
	
	while(tam != 0){
		
		for(i=0;i<tam;i++){
			
			for(j=0;j<tam;j++){
				
				scanf("%d",&vet[i][j]);	
				
				
			}
			
		}	
		
	for(i=0;i<tam;i++){
		
		soma = soma + vet[0][i];
		
	}	
	
	if(quadCheck(vet,tam,soma)==1)
		printf("NO\n");
		
	else
		printf("YES\n");
		
		
	scanf("%d",&tam);
	soma = 0;
		
	}
	
	return 0;
}




int quadCheck(int vet[30][30],int tam,int max){
	
	int soma = 0;
	int i,j;
	int n2 = tam * tam;
	int check = 0;
	
	// checa se os elementos ate n^2 estao presentes
	
	for(n2;n2>0;n2--){
		
		for(i=0;i<tam;i++){
			
			for(j=0;j<tam;j++){
				
				if(vet[i][j]==n2){
					check = 1;
				}
			}
			
			if(check == 1){
			
				break;
			
			}
			
		}
		
		if(check == 0){
		
			return 1;
		
		}	
		
		check = 0;
		
	}
	
	
	
	
	
	
	
	
	// checa a soma das linhas 
	
	for(i = 0; i<tam; i++){
		
		for(j = 0;j<tam;j++){
			
			soma = vet[i][j] + soma;
			
		}
		
		if(soma != max)
			return 1;
		
		soma = 0;
	
	}

	// checa a soma das colunas
	
	for(i = 0; i<tam; i++){
		
		for(j = 0;j<tam;j++){
			
			soma = vet[j][i] + soma;
			
		}
		
	if(soma != max)
		return 1;
		
	soma = 0;
	
	}
	
	
	// checa a diagonal principal

	j = 0;
	
	for(i=0;i<tam;i++){
		
		soma = soma + vet[i][j];
		j++;
		
	}
	
	if(soma != max){
		return 1;
	}
	
	
	// checa a diagonal secundaria	
	
	soma = 0;
	j = 0;
	

	
	for(i=tam-1;i>=0;i--){
		
		soma = soma + vet[j][i];
		j++;
		
	}
	
	if(soma != max){
		return 1;
	}
	
	
	// se tudo der certo retornara um 0
	
	return 0;
	
	
	
}
