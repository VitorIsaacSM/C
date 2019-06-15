#include"List.h"


using namespace std;



int main(){
	
	List *lista = new List();
	
	Node a("inicial","teste","primeira",1);
	Node b("inicial1","teste","primeira",2);
	Node c("inicial2","teste","primeira",3);
	Node d("inicial3","teste","primeira",4);
	
	
	lista->insertFirst(&a);
	lista->insertLast(&b);
	lista->insertLast(&c);
	lista->insertFirst(&d);
	//lista->removeFirst();
	//lista->removeLast();
	Node *f = lista->searchNode("inicial2");
	cout << f->getName() << endl;
	
	lista->printList();
	
	
	
	
	
	return 0;
	
	
}
