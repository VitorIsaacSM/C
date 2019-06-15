// Vitor Isaac Sitton Maia

#include <iostream>


//#include <stdbool.h>

using namespace std;

typedef struct stack{

	int *vet; // vetor
	int topA; // topo da primeira pilha que começara em 0 e sera incrementada
	int size; // tamanho do vetor

} stack;


class Stack {

	private:
		int *vet;
		int topA;
		int size;

	public:
		
		Stack(int t);
		~Stack();
		bool push(int val);
		void printArray();
		int pop();
		int search(int val);
		int find(bool m);
		void overflow();

};

void PilhaSetup();


