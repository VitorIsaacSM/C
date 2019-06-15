// Vitor Isaac Sitton Maia
// Conversor de bases numericas (trabalha com as bases: 2,3,4,5,6,7,8,10,16)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void convert(int decVal, int baseF);
void check(int baseI,int baseF);

int main () {
	
	char num[100];   // numero em formato de texto
	int baseI,baseF; // base inicial e base final
	long decVal;     // valor
	char * ptr;      
	
	
	printf("informe a base do valor:\n");
	scanf("%d",&baseI);
	getchar();
	printf("informe o valor:\n");
	fgets(num,100,stdin);
	printf("informe a base do valor de saida:\n");
	scanf("%d",&baseF);
	
	
	check(baseI,baseF);
	
	decVal = strtol(num,&ptr,baseI);
	
	convert(decVal,baseF);

	return 0;
}

void convert(int decVal, int baseF){
	
	if(baseF==8){
		printf("o valor de saida para a base %d eh = %o",baseF,decVal);
		return;
		
	}
	
	if(baseF==16){
		printf("o valor de saida para a base %d eh = %X",baseF,decVal);
		return;
		
	}
	
	if(baseF==10){
		printf("o valor de saida para a base %d eh = %d",baseF,decVal);
		return;
		
	}
	
	if((baseF<8)&&(baseF>1)){
		
		int soma = 0,res,i;
		
		res = decVal;
		
		for(i=0;res>0;i++){
			
			soma = soma + ((res%baseF) * (pow(10,i)));
			res = res/baseF;
			
			
		}
		
		
		printf("o valor de saida para a base %d eh = %d",baseF,soma);
		return;
		
		
	}
	
}

void check(int baseI,int baseF){
	
	if((baseI>=17)||(baseF>=17)){
		
		printf("entrada invalida de base.\n");
		exit(1);	
		
	}
	
	if((baseI<=1)||(baseF<=1)){
		
		printf("entrada invalida de base.\n");
		exit(1);	
		
	}
	
	if((baseI==9)||(baseF==9)){
		
		printf("entrada invalida de base.\n");
		exit(1);	
		
		
	}
	
	if( ((baseI>=11)&&(baseI<=15)) ||( (baseF>=11)&&(baseF<=15))){
		
		printf("entrada invalida de base.\n");
		exit(1);	
		
		
	}
	
	
	
}
	
