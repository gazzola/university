#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){

	int n;
	double x;
	int result;
	int a, b, c;

	while(true){

		cin >> a >> b >> c;
		
		if(a == 0)
			break;

		x = abs(double(a*b)/(c-a));
		x *= c;
		result = x;

		if(result == 1)
			cout << result << " pagina" << endl;
		else
			cout << result << " paginas" << endl;
	}

	return 0;
}