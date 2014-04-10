#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int fuel, a=0, g=0, d=0;

	while(true){
		cin >> fuel;

		if(fuel == 1)
			a++;
		else if(fuel == 2)
			g++;
		else if(fuel == 3)
			d++;

		if(fuel == 4)
			break;
	}

	cout << "MUITO OBRIGADO" << endl;
	cout << "Alcool: " << a << endl; 
	cout << "Gasolina: " << g << endl;
	cout << "Diesel: " << d << endl;

	return 0;
}