// Vitor Isaac Sitton Maia
// Conversor de temperatura (Celsius, Fahrenheit, Kelvin)

#include<iostream>
#include<string>

using namespace std;

int main(){

    string textos[3] = {"Celsius", "Fahrenheit", "Kelvin"};
    int unidade_in;
    int unidade_out;
    double val;
    double result;

    for(int i = 0; i<3; i++){
        cout << "(" << i << ") - " << textos[i] << endl;
    }

    cin >> unidade_in;
    cout << "digite o valor em " << textos[unidade_in] << endl;
    cin >> val;

    for(int i = 0; i<3; i++){
        if(i != unidade_in){
            cout << "(" << i << ") - converter para " << textos[i] << endl;
        }
    }
    cin >> unidade_out;

    if(unidade_in == 0){
        if(unidade_out == 1){
            result = (1.8 * val) + 32;
            cout << val << " " << textos[0] << " = " << result << " " << textos[1] << endl;            
        }
        else{
            result = val + 273.15;
            cout << val << " " << textos[0] << " = " << result << " " << textos[2] << endl;            
        }
    }

    else if(unidade_in == 1){
         if(unidade_out == 0){
            result = (val - 32) / 1.8;
            cout << val << " " << textos[1] << " = " << result << " " << textos[0] << endl;            
        }
        else{
            result = (val - 32) * (5.0 / 9.0) + 273.15;
            cout << val << " " << textos[1] << " = " << result << " " << textos[2] << endl;            
        }
    }

    else{
        if(unidade_out == 0){
            result = val - 273.15;
            cout << val << " " << textos[2] << " = " << result << " " << textos[0] << endl;            
        }
        else{
            result = (val - 273.15) * (9.0 / 5.0) + 32;
            cout << val << " " << textos[2] << " = " << result << " " << textos[1] << endl;            
        }
    }

    return 0;

}