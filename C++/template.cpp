#include <iostream>
#include <string>

using namespace std;


template<typename T>
class quad {

	private:
		T x;
		T y;
		
	public:
		quad(){
			x = 0;
			y = 0;
		}
		
		
		void set(T a, T b){		
			x = a;
			y = b;		
		}
		
		
		T getArea(){
		
			return (x * y);
		
		}
};


int main(){

	quad<int> dQuad;
	
	dQuad.set(5.5555555555, 5.5555555555);
	
	cout << dQuad.getArea() << endl;

}
