// Vitor Isaac Sitton Maia

#include"queue.h"

void FilaSetup(){
	
	int i;
	int x;
	int val;
	int j;

	cout << "digite o tamanho da fila " << endl;
	cin >> j;	

	Queue *q = new Queue(j);
	

	
	do{
		cout << endl << endl;
		cout << "(1). Enqueue " << endl;
		cout << "(2). Dequeue " << endl;
		cout << "(3). Print " << endl;
		cout << "(4). Search " << endl;
		cout << "(5). Maior " << endl;
		cout << "(6). Menor " << endl;
		cout << "(7). Exit " << endl;		
		cin >> i;
		
		switch(i){
			case 1:
				cout << "digite um inteiro para ser adicionado na fila:" << endl;
				cin >> val;
				
				if(q->enQueue(val)==true){
					cout << "valor " << val << " adicionado a posicao " << q->getNum() << " da fila." << endl;
				}
				
				else{
					cout << "Queue Overflow. Falha adicionar um novo elemento" << endl;
				}
				
				break;

			case 2:
				val = q->deQueue();
				if( val != -1){
					cout << "valor " << q->getVet(val) << " removido da posicao 1 da fila" << endl;	
				}
				else{
					cout << "queue underflow. falha ao retirar um elemento..." << endl;
				}
				break;
			case 3: 
				q->printQ();
				break;
			case 4:
				cout << "digite um inteiro para ser procurado na fila:" << endl;
				cin >> val;
				x = q->searchQ(val);
				if(x !=(-1)){
					cout << endl << "valor " << val << " encontrado na posicao " << x+1 << endl;
				} 
				break;
			case 5:
				if(q->getNum() == 0){
					cout << "a fila esta vazia" << endl;
					break;
				}
				cout << "o maior valor da fila eh  " << q->findQ(true) << endl; 
				break;
			case 6:
				if(q->getNum() == 0){
					cout << "a fila esta vazia" << endl;
					break;
				}
				cout << "o menor valor da fila eh  " << q->findQ(false) << endl;
				break;

		}

	}
	while(i!=7);
	
	q->~Queue();
	
	return;
	
}

int Queue::getVet(int i){

	return vet[i];

}

int Queue::getNum(){

	return num;

}

int Queue::findQ(bool m){

	int i;
	int nm;
	nm = vet[head];

	if(m == false){
	
		for(i = 0; i<num; i++){

			if(i+head < size){
				
				if(vet[i+(head)] < nm){
					nm = vet[i+(head)];
				}
			}
			
			else{
				if(vet[i+(head)-(size)] < nm){
					nm = vet[i+(head)-(size)];
				}
			}
			
		}

		return nm;
	}

	else{

		for(i = 0; i<num; i++){

			if(i+head < size){
				
				if(vet[i+(head)] > nm){
					nm = vet[i+(head)];
				}
			}
			
			else{
				if(vet[i+(head)-(size)] > nm){
					nm = vet[i+(head)-(size)];
				}
			}
			
		}

		return nm;
	}





}

int Queue::searchQ(int val){
	
	int i;
	
	for(i = 0; i<num; i++){

		if(i+head < size){
			
			if(vet[i+(head)] == val){
				return i;
			}	
		}
		
		else{
			if(vet[i+(head)-(size)] == val){
				return i;
			}
		}	
	
	}

	cout << "valor nao encontrado "<< endl;
	return -1;
	
}

void Queue::printQ(){

	int i;
	
	cout << endl;
	
	for(i=0; i<num; i++){
		
		if(i+head < size){
			cout << 1+i << ". = "<< vet[i+(head)];
			
			if(i+(head) == head){
				cout << " - head";
			}
			
			cout << endl ;
		}
		
		else{
			cout << 1+i << ". = "<< vet[i+(head)-(size)];
			
			if(i+(head)-(size) == head){
				cout << " - head";
			}
			
			cout << endl ;
			
		}

	}
	
	if(num == 0){
			cout << "A fila esta vazia" << endl << endl;
	}
	
	return;
}

int Queue::deQueue(){
	
	int x = head;
	
	if(num == 0){
		head = 0;
		tail = 0;
		return -1;
		
	}
	
	head += 1;
	num--;
	if(head == size){
		head = 0;
	}
	return x;
	
}

bool Queue::enQueue(int val){


	// verifica se a fila esta cheia. A variavel num tem o valor do numero de elementos contidos na fila atualmente
	if(num >= size){ 
		return false;		
	}
	
	vet[tail] = val; // atribui o valor a ultima posicao da fila
	
	tail += 1; // adiciona 1 a variavel tail, que representa a proxima posicao em que sera adicionado um elemento
	
	num++; // adiciona 1 ao numero de elementos contidos na fila
	
	// verifica se a fila chegou ao limite.
	if(tail == size){
		tail = 0;
	}
	return true ;


}

Queue::Queue(int t){




	//scanf("%d", &t); // entrada do valor para o tamanho do vetor

	while(t < 1){
		cout << "Tamanho invalido. Digite o tamanho da fila novamente:"<< endl;
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

	head = 0;
	tail = 0;
	num = 0;
	size = t; // guarda o valor do tamanho digitado pelo usuario dentro da struct.
		
}

Queue::~Queue(){


	free(vet);


}

