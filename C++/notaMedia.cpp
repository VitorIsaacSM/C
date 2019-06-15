#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Calcula a nota media de 6 notas (descartando as 2 menores)

using namespace std;


int main(){
	
	int notas[6];
	
	double total = 0;

	for(int i = 0; i < 6; i++){
		cin >> notas[i];
		total = total + notas[i];
	}
	
	int menor1 = notas[0];
	int menor2 = notas[1];
	
	for(int i = 0; i < 6; i++){
		if(notas[i] < menor1){
			menor2 = menor1;
			menor1 = notas[i];			
		}
	}
	
	total = total - menor1- menor2;
	
	cout << endl << "total eh "<< (total/4.0) << endl;;
	
}
