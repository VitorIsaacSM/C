#include"List.h"


using namespace std;



int main(){
	
	List *lista = new List();
	List *lista2 = new List();
	
	Node a("inicial","teste","primeira",1);
	Node b("inicial1","teste","primeira",2);
	Node c("inicial2","teste","primeira",3);
	Node d("inicial3","teste","primeira",4);
	Node f("insertTest","teste","primeira",34);
	
	lista->insertFirst(&a);
	lista->insertLast(&b);
	lista->insertLast(&c);
	lista->insertFirst(&d);
	//Node *f = lista->searchNode("inicial2");
	//cout << f->getName() << endl;
	
	
	lista2->cat(lista);
	lista2->insert(&f,4);
	lista2->printList();
	
	
	
	
	
	return 0;
	
	
}
