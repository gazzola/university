#include <iostream>
#include <iomanip>

using namespace std;



int main(){
	
	int a, b, x;

	while(true){
		
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;

		int *vet = new int[a]();

		for(int i=0; i<b; i++){
			for(int j=0; j<a; j++){
				cin >> x;
				vet[j] += x; 
			}
		}

		bool ok = false;
		for(int i=0; i<a; i++){
			if(vet[i] == b){
				ok = true;
				break;
			}
		}

		if(ok)
			cout << "yes" << endl;
		else
			cout << "no" << endl;


	}

	return 0;
}