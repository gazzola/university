#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int b, n;

	while(true){

		cin >> b >> n;
		
		if(b==0 && n==0)
			break;


		bool vaiprecisar = false;

		int *reservas = new int[b];
		for(int i=0; i<b; i++)
			cin >> reservas[i];

		for(int i=0; i<n; i++){
			int d, c, v;
			cin >> d >> c >> v;

			reservas[d-1] -= v;
			reservas[c-1] += v;
		}

		for(int i=0; i<b; i++){
			if(reservas[i] < 0){
				vaiprecisar = true;
				break;
			}
		}

		if(vaiprecisar)
			cout << "N" << endl;
		else
			cout << "S" << endl;

		delete[] reservas;

	}

	return 0;
}