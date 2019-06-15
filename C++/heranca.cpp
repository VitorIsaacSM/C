#include <iostream>
#include <string>

using namespace std;

class funcionario {

	private:
		double salarioBase;
		int cargaHoraria;
		string nome;
		
	public:
		funcionario(double sal, int c, string n) : salarioBase(sal),cargaHoraria(c), nome(n){
		}
		virtual double getSalario() = 0; 
		
		double getBase(){
			return salarioBase;
		}
		int getCargaH(){
			return cargaHoraria;
		}
		void setSal(double s){
			salarioBase = s;
		}
		
};

class caixa : public funcionario {

	public:
		caixa(double s, string nome):funcionario(s,120,nome){
		
			try{
			
				if(s > 8000 || s < 900){
									
					throw s;
				
				}
				
				else{				
					cout << "funcionario caixa criado " << endl;				
				}
						
			}
			
			catch(double excpt){
				cout << "salario invalido, portanto foi setado para o valor pre definido 1200" << endl;	
				setSal(1200);				
			}		
		}
		
		double getSalario(){
		
			double inss = getBase() * 0.08;
			
			return getBase() - inss;
		}

};

class gerente : public funcionario {

	public:
		gerente(double s, int c, string nome): funcionario(s,c,nome){
		
		}
		
		double getSalario(){
		
			double sal = getBase() * getCargaH();
		
			return sal - (sal * 0.08);
						
		}
};



int main(){

	funcionario* f = new caixa(1000,"ze");

	cout << f->getSalario() << endl;


}
