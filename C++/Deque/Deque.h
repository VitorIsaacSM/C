//vitor isaac sitton maia
#include <iostream>

using namespace std;


class Deque{
	
	private:
		int *vet;
		int front;
		int rear;
		int size;
		
		
	public:
		Deque(int t);
		~Deque();
		void insert_back(int x);
		void insert_front(int x);
		void delete_back();
		void delete_front();
		bool is_empty();
		bool is_full();
		void print();
	
};

