#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


int main(){
	
	
	int n, c, k, x;
	int vet[101];

	while(true){

		cin >> n >> c >> k;

		if(c==0 && n==0 && k==0)
			break;

		memset(vet, 0, sizeof(vet));

		for(int i=0; i<n; i++){
			for(int j=0; j<c; j++){
				cin >> x;
				vet[x]++;
			}
		}

		int menor=vet[1], posult=1;
		for(int i=1; i<=k; i++){
			if(vet[i] <= menor){
				menor = vet[i];
				posult = i;
			}
		}


		for(int i=1; i<=posult; i++){
			if(vet[i] == menor){
				if(posult != i)
					cout << i << " ";
				else
					cout << i;
			}
		}
		
		cout << endl;

	}

	return 0;
}