
#include "tarefa.h"

// vitor isaac sitton maia

bool comparaTarefa(tarefa first, tarefa second){

	// funcao parametro do sort
	// eu considero bem horrivel esses if's, mas eu nao tive uma ideia melhor

	if( first.getAno() < second.getAno())
		return true;
	if( first.getAno() > second.getAno())
		return false;
	if( first.getMes() < second.getMes())
		return true;
	if( first.getMes() > second.getMes())
		return false;
	if( first.getDia() < second.getDia())
		return true;
	if( first.getDia() > second.getDia())
		return false;
	if( first.getHora() < second.getHora())
		return true;
	if( first.getHora() > second.getHora())
		return false;
	if( first.getMin() < second.getMin())
		return true;
	if( first.getMin() > second.getMin())
		return false;
	
}

void LimitPrint(list<tarefa> l){

	l.sort(comparaTarefa);

	for( auto& i : l){
		cout << endl;
		cout << "- Titulo: " << i.getTitulo() << endl;
		cout << "- Descricao: " << i.getDesc() << endl;
		cout << "- Limite: ";  i.printData(); cout << endl;
	}

}

bool checkTarefa(tarefa t){

	time_t b = std::time(0);   // get time now
    tm* now = std::localtime(&b);
  
   
    int ano = now->tm_year + 1900;
    int mes = now->tm_mon + 1;
    int dia = now->tm_mday;
    
    int maxDia;
    
  
    switch(mes){
    
		case 1:
			maxDia = 31;
			break;
		case 2:
			maxDia = 28;
			break;
		case 3:
			maxDia = 31;
			break;
		case 4:
			maxDia = 30; 
			break;
		case 5:
			maxDia = 31; 
			break;
		case 6:
			maxDia = 30 ;
			break;
		case 7:
			maxDia = 31;
			break;
		case 8:
			maxDia = 31;
			break;
		case 9:
			maxDia = 30; 
			break;
		case 10:
			maxDia = 31;
			break;
		case 11:
			maxDia = 30;
			break;
		case 12:
			maxDia = 31;
			break;
		default:
			maxDia = -1;
			break;
			
    }
    
    if(t.getAno() + 1900 < 0){
		cout << endl << "Ano inválido falha ao adicionar tarefa" << endl;
		return false;
    }
    if(t.getMes() < 0){
		cout << endl << "Mes inválido falha ao adicionar tarefa" << endl;
		return false;
    }
    if( maxDia < 0){
		cout << endl << "Dia inválido falha ao adicionar tarefa" << endl;
		return false;    
    }    
    if(t.getHora() < 0){
		cout << endl << "Hora inválida falha ao adicionar tarefa" << endl;
		return false;
    }
    if(t.getMin() < 0){
		cout << endl << "Minutos inválidos falha ao adicionar tarefa" << endl;
		return false;
    }
    
    if(dia > maxDia){
		cout << endl << "Dia inválido falha ao adicionar tarefa" << endl;
		return false;   
    }
    
    if(mes > 12){
    	cout << endl << "Mes inválido falha ao adicionar tarefa" << endl;
		return false;
    
    }
    
    if( ano < t.getAno() + 1900){
		cout << endl << "Ano inválido falha ao adicionar tarefa" << endl;
		return false;
    }
    if( mes < t.getMes()){
		cout << endl << "Mes inválido falha ao adicionar tarefa" << endl;
		return false;
    }
    if( dia < maxDia){
		cout << endl << "Dia inválido falha ao adicionar tarefa" << endl;
		return false;    
    }    
    if(t.getHora() > 23){
		cout << endl << "Hora inválida falha ao adicionar tarefa" << endl;
		return false;
    }
    if(t.getMin() > 59){
		cout << endl << "Minutos inválidos falha ao adicionar tarefa" << endl;
		return false;
    }
    
    return true;

}



bool isNumeric(char c){

	switch(c){
	
		case '0':
			return true;
			break;
		case '1':
			return true;
			break;
		case '2':
			return true;
			break;
		case '3':
			return true;
			break;
		case '4':
			return true;
			break;
		case '5':
			return true;
			break;
		case '6':
			return true;
			break;
		case '7':
			return true;
			break;
		case '8':
			return true;
			break;
		case '9':
			return true;
			break;
		default:
			return false;
	}

}

int getInt(){

	string temp;
	stringstream conversor;
	int out;

	getline(cin, temp);
	
	for(int i = 0; i < temp.size(); i++){
	
		if(isNumeric(temp.at(i))){
		
			continue;
		
		}
		
		else{
			cout << "entrada invalida digite novamente:" << endl;
			return getInt();
		
		}

	}
	
	conversor << temp;

	conversor >> out;
	
	return out;

}


// constructor
tarefa::tarefa(string t, string dsc){

	titulo = t;
	desc = dsc;

	cout << "Digite a data limite desta tarefa (formato: dd/mm/aaaa hh:mm)" << endl;
	cout << "Dia: ";
	d.dia = getInt();
	cout << "Mes: ";
	d.mes = getInt();
	cout << "Ano: ";
	d.ano = getInt();
	cout << "Hora: ";
	d.hora = getInt();
	cout << "Minutos: ";
	d.min = getInt();

}

// getters
string tarefa::getTitulo(){
	return titulo;
}
string tarefa::getDesc(){
	return desc;
}

int tarefa::getAno(){
	return d.ano;
}

int tarefa::getMes(){
	return d.mes;
}

int tarefa::getDia(){
	return d.dia;
}

int tarefa::getHora(){
	return d.hora;
}

int tarefa::getMin(){
	return d.min;
}

void tarefa::printData(){

	//imprime data e hora
	cout << setw(2) << setfill('0') << d.dia << "/"; 
	cout << setw(2) << setfill('0') << d.mes << "/";
	cout << setw(4) << setfill('0') << d.ano <<  "  ";
	cout << setw(2) << setfill('0') << d.hora << ":" ;
	cout << setw(2) << setfill('0') << d.min << endl;
}


