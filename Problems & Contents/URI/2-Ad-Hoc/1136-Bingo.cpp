#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;


int main(){
	
	int n, b, x;
	vector<int> bolas;
	int vet[92];

	while(true){

		cin >> n >> b;
		if(n == 0 && b == 0)
			break;

		memset(vet, 0, sizeof(vet));
		int maior = 0;
		bool temZero = false;

		for(int i=0; i<b; i++){
			cin >> x;
			bolas.push_back(x);
			
			if(x > maior)
				maior = x;
			
			if(x == 0)
				temZero = true;
		}

		if(!temZero || maior < n){
			cout  << "N" << endl;
		}
		else{

			for(int i=0; i<b; i++){
				for(int j=0; j<b; j++){
					int pos = abs(bolas[i]-bolas[j]);
					vet[pos] = 1;
				}
			}

			bool ok = true;
			for(int i=0; i<=n; i++){
				if(vet[i] == 0){
					ok = false;
					break;
				}
			}


			if(ok)
				cout << "Y" << endl;
			else
				cout << "N" << endl;

		}

		bolas.clear();
	}	


	return 0;
}