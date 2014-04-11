#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

	double a, b, c, delta, r1, r2;
	cin >> a >> b >> c;
	delta = ((b*b) - (4*a*c));

	if(a == 0 || delta < 0){
		cout << "Impossivel calcular" << endl;
	}
	else{
		r1 = (-b + sqrt(delta)) / (2*a);
		r2 = (-b - sqrt(delta)) / (2*a);
		cout << fixed << setprecision(5)
			 << "R1 = " << r1 << endl
			 << "R2 = " << r2 << endl;
	}


	return 0;
}