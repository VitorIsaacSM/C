// Vitor Isaac Sitton Maia
#include"stack.h"


void PilhaSetup(){
	
	int i;
	int val;
	int x;

	cout << "digite o tamanho da pilha " << endl;
	cin >> x;

	Stack *pilha = new Stack(x);

	do{
		cout << endl << endl;
		cout << "(1). Push " << endl;
		cout << "(2). Pop " << endl;
		cout << "(3). Print " << endl;
		cout << "(4). Search " << endl;
		cout << "(5). Maior " << endl;
		cout << "(6). Menor " << endl;
		cout << "(7). Exit " << endl;		
		cin >> i;

		switch(i){
			case 1:
			cout << "digite um inteiro para ser adicionado na pilha:" << endl;
			cin >> val;
			pilha->push(val);
			break;

			case 2:
				pilha->pop(); 
				break;
			case 3:	pilha->printArray();
				break;
			case 4:cout << "digite um inteiro para ser procurado na pilha:" << endl;
			cin >> val;
			
			if(pilha->search(val)!=(-1)){
				cout << endl << "valor " << val << " encontrado na posicao " << pilha->search(val) << endl;
			} break;
			case 5:cout << "o maior valor da pilha eh  " << pilha->find(true) << endl; break;


			case 6:cout << "o menor valor da pilha eh  " << pilha->find(false) << endl; break;

		
		}
	}
	while(i!=7);

	pilha->~Stack();

	return;
}



int Stack::pop(){

	int val; // valor de index da posiçao do elemento removido
		
	// se o topo da pilha A for maior que 0 entao existem elementos na pilha A. logo o pop pode ser executado	
	if(topA > 0){
		val = topA-1;
		//printf("valor %d removido da posicao %d do vetor na pilha A \n\n",vet[val],(topA));
		cout << "valor " <<  vet[val] << " removido da posicao "<< topA << " da pilha" << endl;
		topA -= 1;
		return (vet[topA]);
	}
	
	else{
		// caso nao existam elementos nesta pilha .
		//printf("Stack underflow. Nao existem elementos para serem retirados nesta pilha\n\n");
		cout << "Stack underflow. Nao existem elementos para serem retirados nesta pilha" << endl << endl;
		return -1 ;
	}
	

}


void Stack::printArray(){

	int i;

	//printf("\nVetor inteiro: \n");

	for(i=0; i<size; i++){
		//printf("%d. = %d ",i+1,vet[i]);
		cout << i+1 <<". = " << vet[i];
		// lista todos os elementos que das duas pilhas

		if(i == topA)
			//printf(" - topo da pilha A"); // o topo de uma pilha é a posiçao em que o proximo elemento sera adicionado
			cout << " topo da pilha " << endl;

		else
			cout << endl;

	}

	if(topA == size)
	cout << " pilha cheia " << endl;



}


bool Stack::push(int val){


	
	if(topA >= size){
		// Enquanto o topo da pilha A for menor que o topo da pilha B nao acontece overflow
		// Caso o valor do topo pilha A esteja maior que o da pilha B nao sera possivel adicionar elementos ( a nenhuma das pilhas)
		/* Se os valores do topo das duas pilhas forem iguais, nao ha nenhum problema pois o topo representa a proxima posicao
	 	onde sera adicionado um elemento, e nao a posicao do ultimo elemento de uma pilha. */
		//cout << "Stack Overflow. Falha adicionar um novo elemento" << endl;
		//return false;		
		overflow();
	}

	
	vet[topA] = val;
	topA += 1;
	//	printf("valor %d adicionado a posicao %d do vetor na pilha A \n\n",val,(topA));
	cout << "valor " << val << " adicionado a posicao " << topA << " da pilha." << endl;
	return true ;


}


Stack::Stack(int t){

	// tamanho do vetor que sera dado pelo usuario e passado para a variavel size que esta na struct

	//printf("\nDigite o tamanho do vetor que contera as pilhas\n");
	
	//scanf("%d", &t); // entrada do valor para o tamanho do vetor
	
	while(t < 1){
		cout << "Tamanho invalido. Digite o tamanho da pilha novamente:"<< endl;
		cin >> t;
	}

	vet = (int *) malloc(sizeof(int) * t); // alocaçao do tamanho do vetor
	if (vet == NULL) {
	    //printf("Falha ao alocar memoria\n");
		cout << "falha ao alocar memoria" << endl;
		exit(EXIT_FAILURE);
		// checa se a alocaçao de memoria foi sucedida
		// imprime uma mensagem de erro e fecha o programa em caso de falha na alocaçao
	}

	topA = 0;  /* define o topo da pilha A como 0 
	O topo desta pilha começará em 0 e aumentara conforme elementos sao adicionados à mesma. 
	O topo representa a posiçao em que o proximo elemento sera adicionado. */

	size = t; // guarda o valor do tamanho digitado pelo usuario dentro da struct.
		
}

Stack::~Stack(){

	free(vet);

}

int Stack::find(bool m){

	int i;
	int nm;
	nm = vet[0];

	if(topA == 0){
		cout << "a pilha esta vazia. " << endl;
		return 0;

	}

	if(m == false){
	
		for(i = 0; i<topA; i++){

			if(vet[i] < nm){
				nm = vet[i];
				
			}

		}

		return nm;
	}

	else{

		for(i = 0; i<topA; i++){

			if(vet[i] > nm){
				nm = vet[i];
				
			}

		}
		
		return nm;
	}





}

int Stack::search(int val){

	bool found = false;
	int i;
	
	for(i = 0; i<topA; i++){

		if(vet[i] == val){
			found = true;
			break;
		}
			
	}

	if(found == true){

		return i;

	}

	cout << "valor nao encontrado "<< endl;
	return -1;
	
}

void Stack::overflow(){
	
		int i;
		int *aux;
		aux = (int *) malloc(sizeof(int)*size);
	
		for(i = 0; i < size; i++){
			
			aux[i] = vet[i];
		
		}
	
		free(vet);
		vet = (int *) malloc(sizeof(int)*(size*2));
		
		for(i = 0; i < size; i++){
			
			vet[i] = aux[i];
		
		}
		
		size = size*2;
			
		free(aux);

}








