#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n, init=1;
	cin >> n;

	while(n--){
		for(int i=init; i<init+3; i++)
			cout << i << " ";

		cout << "PUM" << endl;
		init = i;
	}

	cout << "MUITO OBRIGADO" << endl;
	cout << "Alcool: " << a << endl; 
	cout << "Gasolina: " << g << endl;
	cout << "Diesel: " << d << endl;

	return 0;
}