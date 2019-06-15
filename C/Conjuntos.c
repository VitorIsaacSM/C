// Vitor Isaac Sitton Maia

// Checa se os vetores tem o mesmo conjunto (se os valores de um deles pertence ao conjunto de valores do outro)

#include<stdio.h>

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
		
			
		for(i=0;i<n1;i++){
			
			check = 0;
			
			for(j=0;j<n2;j++){
				
				if(v1[i] == v2[j]){
					check = 1;
					break;
				}
				
			}
			
			if(check == 0){
				printf("NO\n");
				break;
				
			}
			
		}
	
		if(check==1){
			
			for(i=0;i<n2;i++){
			
				check = 0;
			
				for(j=0;j<n1;j++){
				
					if(v2[i] == v1[j]){
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
