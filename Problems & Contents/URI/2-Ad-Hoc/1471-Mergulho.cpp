#include <iostream>
#include <iomanip>

using namespace std;

int estaNoVetor(int *v, int ele, int tam){
	for(int i=0; i<tam; i++)
		if(v[i] == ele)
			return true;

	return false;
}

int main(){
	
	int a, b;

	while(cin >> a >> b){
		int *m = new int[a];
		
		for(int i=0; i<b; i++){
			cin >> m[i];
		}

		int count = 0;
		for(int i=1; i<=a; i++){
			if(!estaNoVetor(m, i, b))
				cout << i << " ";
			else
				count++;
		}

		if(count == a)
			cout << "*";

		cout << endl;

		delete[] m;
	}

	return 0;
}