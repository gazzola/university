#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;


int main(){
	
	int n, x;
	int vet[2001];
	memset(vet, 0, sizeof(vet));

	int maior = 1;

	cin >> n;

	while(n--){
		cin >> x;
		vet[x]++; 
		if(x > maior)
			maior = x;
	}

	for(int i=1; i<=maior; i++)
		if(vet[i] > 0)
			cout << i << " aparece " << vet[i] << " vez(es)" << endl;


	return 0;
}
