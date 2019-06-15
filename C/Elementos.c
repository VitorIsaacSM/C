// Vitor Isaac Sitton Maia

// checa se um vetor tem os Mesmo elementos (mesmos valores em qualquer ordem)

#include<stdio.h>




void subtrai(int * vet, int n, int * max);

int main(void){
	
	int n1 = 1,n2 = 1;
	int v1[100], v2[100];
	int i,j;
	int check ;
	
	scanf("%d%d",&n1,&n2);
	
	
		
	
	while( (n1 != 0 ) || ( n2!= 0)){
		
		
		
		for(i=0;i<n1;i++){
		
			scanf("%d",&v1[i]);
		
		
		}
	
		for(i=0;i<n2;i++){
			
			
		
			scanf("%d",&v2[i]);
		
		
		}
		
			
			
		if(n1 != n2){
			
			printf("NO\n");
			
		}
		
		else{
	
		
			for(i=0;i<n1;){
			
				check = 0;
			
				for(j=0;j<n2;j++){
				
					if(v1[i] == v2[j]){
						
						subtrai(v1,i,&n1);
						subtrai(v2,j,&n2);
						check = 1;
						break;
						
					}
				
				}
			
				if(check == 0){
					printf("NO\n");
					break;
				
				}
			
			}
	
	
		}
	
		if(check == 1){
			
			printf("YES\n");
		}
	
	
	
	
		scanf("%d%d",&n1,&n2);
		
	}
		
		
	return 0;
}



void subtrai(int * vet, int n, int * max){
	
	int i;
	
	for(i = n; i<*max;i++){
		
		vet[i] = vet[i+1]; 
		
	}
	
	*max = *max - 1;
	
	return ;
	
}




