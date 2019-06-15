// Vitor Isaac Sitton Maia
// Checa se 2 vetores sao identicos (condiçao de parada é 0 no tamanho do vetor)

#include<stdio.h>


int main(void){
	
	int n1 = 1,n2 = 1;
	int v1[100], v2[100];
	int i;
	int check ;
	
	
	scanf("%d",&n1);

	if(n1==0){
		return 0;
	}

	scanf("%d",&n2);

	if(n2==0){
		return 0;
	}
	
	
		
	
	while( (n1 != 0 )||( n2!= 0)){
		
		check = 0;
		
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
			
			for(i=0;i<n1;i++){
				
				if(v1[i] != v2[i]){
					
					check = 1;
					break;
				}
				
			}
			
			
			if(check == 1){
				printf("NO\n");
			}
			
			if(check == 0){
				printf("YES\n");
			}
			
			
		}
	
		scanf("%d",&n1);

		if(n1==0){
			return 0;
		}

		scanf("%d",&n2);

		if(n2==0){
			return 0;
		}
		
	}
	
	
	
	return 0;
}
