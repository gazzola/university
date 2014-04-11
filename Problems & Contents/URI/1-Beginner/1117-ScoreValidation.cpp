#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int c = 0;
	double notes[2], t;

	while(true){
		cin >> t;

		if(t >= 0 && t <= 10){
			notes[c] = t;
			c++;
		}
		else{
			cout << "nota invalida" << endl;
		}

		if(c == 2)
			break;

	}

	cout << fixed << setprecision(2) 
		 << "media = " << (notes[0]+notes[1])/2 << endl;

	return 0;
}