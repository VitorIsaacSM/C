// Diz se o quadrado do tabuleiro é preto ou branco (considerar as lateras a,b,c,d,e... como 1,2,3,4,5...)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	int x,y;
	
	cin >> x;
	cin >> y;
	
	if(x % 2 != 0){
		if(y % 2 != 0){
			cout << "preto" << endl;
		}
		else
			cout << "branco" << endl;
	}
	else{
		if(y % 2 != 0){
			cout << "branco" << endl;
		}
		else
			cout << "preto" << endl;	
	}

}
