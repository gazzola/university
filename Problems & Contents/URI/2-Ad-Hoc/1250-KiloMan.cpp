#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


int main(){
	
	char c;
	int t, x, n, vet[50];

	cin >> n;
	
	while(n--){

		int downs = 0;

		cin >> t;

		for(int j=0; j<t; j++)
			cin >> vet[j];

		
		for(int j=0; j<t; j++){
			cin >> c;
			if(c == 'J' && vet[j] > 2)
				downs++;
			else if(c == 'S' && vet[j] <= 2)
				downs++;
		}
	
		cout << downs << endl;

	}

	return 0;
}