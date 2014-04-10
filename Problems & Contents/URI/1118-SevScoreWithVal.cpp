#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int x, c=0;
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

		if(c == 2){

			cout << fixed << setprecision(2) 
		 		 << "media = " << (notes[0]+notes[1])/2 << endl;

			while(true){
				cin >> x;

				if(x < 1 || x > 2){
					cout << "novo calculo (1-sim 2-nao)" << endl;
				}
				else{
					cout << "novo calculo (1-sim 2-nao)" << endl;

					if(x == 2)
						return 0;
					else
						break;
				}
			}

			c = 0;
		}

	}

	

	return 0;
}