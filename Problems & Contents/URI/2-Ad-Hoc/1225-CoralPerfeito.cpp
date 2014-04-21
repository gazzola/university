#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	
	int n, cantores[100001];
	while(cin >> n){

		int soma = 0;
		for(int i=0; i<n; i++){
			cin >> cantores[i];
			soma += cantores[i];
		}

		if(soma % n != 0){
			cout << "-1" << endl;
		}
		else{

			//ja que soma%n == 0, media=int
			int media = soma/n;
			int compassos = 1;

			for(int i=0; i<n; i++){
				if(cantores[i] >= media)
					break;

				compassos += media-cantores[i];
			}

			cout << compassos << endl;

		}

	}

	return 0;
}