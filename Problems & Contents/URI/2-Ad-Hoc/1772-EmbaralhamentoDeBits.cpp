#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;



int main(){
	
	long long int n, k, a, b, x, maior, menor;
	bool temp;
	bitset<32> binary;

	while(scanf("%lld %lld", &n, &k) and k > 0){

		binary = n;
		maior = n;
		menor = n;

		while(k--){
			scanf("%lld %lld", &a, &b);

			temp = binary[a];
			binary[a] = binary[b];
			binary[b] = temp;

			x = binary.to_ulong();
			maior = max(maior, x);
			menor = min(menor, x);

		}

		cout << x << " " << maior << " " << menor << endl;
	}


	
	return 0;
}