
// Vitor Isaac Sitton Maia
// 01/09/2018


#include"Entrada.h"



Entrada::Entrada(){
	
	string cpfTemp;
	
	cout << "digite o nome: " << endl;
	getline(cin,full_name);
	
	cout << "digite o CPF: " << endl;
	getline(cin,cpfTemp); 
	this->cpf = toInt(cpfTemp);
	
	
	// garante que o cadastro tera um valor correto
	cadastro = "";
	do{
		if(!cadastro.empty()){
			cout << "valor invalido " << endl << endl;
		}
		
		cout << "digite a situacao cadastral: " << endl;
		cout << "(regular) ou (irregular) " << endl;
		getline(cin,cadastro);
		
		
	}while ((cadastro != "regular") && (cadastro != "irregular"));
	
	next = NULL;
	prev = NULL;
	
}



Entrada::Entrada(string nome, long long int cpf, string cad){
	
	full_name = nome;
	this->cpf = cpf;
	this->cadastro = cad;
	
	next = NULL;
	prev = NULL;
}

Entrada::~Entrada(){
	
	
}

Entrada* Entrada::getNext(){
	
	
		return next;
	
}

void Entrada::setNewCpf(){
	
	string cpfTemp;
	
	cout << "Digite um novo CPF :" << endl;
	getline(cin,cpfTemp); 
	this->cpf = toInt(cpfTemp);
	
	
}
	
void Entrada::setNext(Entrada *n){
	
	
	
	next = n;
	

	
}

Entrada* Entrada::getPrev(){
	
	
		return prev;
	
}
	
void Entrada::setPrev(Entrada *n){
	
	
	
	prev = n;
	

	
}

string Entrada::getName(){
	
	
	return full_name;
	
	}
	
long long int Entrada::getCpf(){
	
	return cpf;
	
} 

string Entrada::getCad(){
	
	
	return cadastro;
	
} 

string Entrada::toString(){
	
	stringstream conteudo;
	
	conteudo << this->getName() << "," << this->getCpf() << "," << this->getCad() << endl;
	
	return conteudo.str();
}

void Entrada::printData(){
	
	cout << endl;
	cout << "Nome     :" << this->getName() << endl;
	cout << "CPF      :" << this->getCpf() << endl;
	cout << "Cadastro :" << this->getCad() << endl << endl;


}

 // funcao que certifica que entrada que esperam numeros inteiros
// recebam de fato numeros inteiros e nao qualquer outra coisa 
long long int toInt(string sel){
	
	stringstream converter;
	long long int val;
	
	if(sel == ""){
		getline(cin,sel);
		val = toInt(sel);
		converter << sel;
	}
	
	else if(!isdigit(sel.at(0))){
		
		cout << "entrada invalida, digite novamente : " << endl;
		getline(cin,sel);
		val = toInt(sel);
		converter << sel;
	}
	
	else{
		// conversor recebe o valor da string e passa esse valor para uma long long int 
		converter << sel;
		converter >> val;
	}
	
	return val;
	
	
}
