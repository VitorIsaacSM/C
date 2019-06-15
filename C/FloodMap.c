// Vitor Isaac Sitton Maia

// Mapa de alagamento

#include<stdio.h>


void printMap(double vet[50][50],int d,double t);

int main(void){
	
	int d; //dimensao
	double vet [50][50];
	int i,j;
	int v; // numero de vezes que sera avaliado
	double t[100]; // valores
	
	scanf("%d",&d);
	
	for(i=0;i<d;i++){
		
		for(j=0;j<d;j++){
			
			scanf("%lf",&vet[i][j]);
			
		}
		
		
	}
	
	scanf("%d",&v);
	
	for(i=0;i<v;i++){
		scanf("%lf",&t[i]);
	}
	
	for(i=0;i<v;i++){
		
		printMap(vet,d,t[i]);
		printf("\n");
		
	}
	
	
	
	
	return 0;
}




void printMap(double vet[50][50],int d,double t){
	
	char map[50][50];
	int i,j;
	
	for(i=0;i<d;i++){
		
		for(j=0;j<d;j++){
			
			if(vet[i][j]<=t){
				
				printf("~");
				continue;
				
			}
			
			printf("X");
		}
		
		printf("\n");
	}
	
	
	
}
