#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;




int main(){
	
	int n, a, b;

	while(true){

		cin >> n;
		if(n == 0)
			break;

		int carrPos[10001], carro[10001];
		bool ok = true;

		for(int i=1; i<=n; i++){
			cin >> a >> b;
			carro[i] = a;
			carrPos[i] = i+b;
			
			if(abs(b) >= n || i+b > n || i+b <= 0)
				ok = false;
		
			for(int j=1; j<=i; j++)
				if(carrPos[j] == i+b && j != i)
					ok = false;
		}

		if(ok){

			for(int i=1; i<=n; i++){
				int menor = 999999, menorPos;

				for(int j=1; j<=n; j++){
					if(carro[j] != -1){
						if(carrPos[j] < menor){
							menor = carrPos[j];
							menorPos = j;
						}
					}
				}

				if(i < n)
					cout << carro[menorPos] << " ";
				else
					cout << carro[menorPos] << endl;

				carro[menorPos] = -1;

			}

		}
		else
			cout << "-1" << endl;

	}
	

	return 0;
}
