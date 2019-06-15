// Vitor Isaac Sitton Maia

#include <iostream>

using namespace std;

typedef struct queue{

	int *vet; // vetor
	int head; // primeiro a entrar
	int tail; // ultimo a entrar
	int size; // tamanho do vetor
	int num;  // numero de elementos na fila

} queue;

class Queue{

	private:
		int *vet;
		int head;
		int tail;
		int size;
		int num;

	public:
		Queue(int t);
		~Queue();
		bool enQueue(int val);
		int deQueue();
		void printQ();
		int searchQ(int val);
		int findQ(bool m);
		int getVet(int i);
		int getNum();
		


};

void FilaSetup();

