#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class pessoa {

	private:
		string name;
		int idade;
		string curso;
		string genero;
		
	public:
		pessoa(string n, int i, string c, string g){
			name = n;
			idade = i;
			curso = c;
			genero = g;
		}
		
		string getName(){
			return name;
		}
		
		int getIdade(){
			return idade;
		}
		
		string getCurso(){
			return curso;
		}
		
		string getGenero(){
			return genero;
		}
		
		string toString(){
			stringstream a;
			a << name << " tem " << idade << " anos. Cursa " << curso << endl;
			return a.str();
		}
};

int main(){

	ifstream inFile;
	inFile.open("txt1.txt");
	
	string n;
	int i;
	string si;
	string c;
	string g;
	
	pessoa *Pessoas[4] ;
	
	while(inFile.good()){
		for(int j = 0; j < 4; j++){
			getline(inFile, n, ',');
			getline(inFile, si, ',');
			getline(inFile, c, ',');
			getline(inFile, g, ',');
			
			stringstream converter;
			converter << si;
			converter >> i;
			
			Pessoas[j] = new pessoa(n, i, c, g);
			cout << Pessoas[j]->toString() << endl;
		}
		
	}
	
	inFile.close();


}
