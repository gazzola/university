#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


typedef long long unsigned int llu;

const llu LIM = 100000;
bool isprime[LIM];
llu prime[LIM];
llu prime_cont = 1;

void crivo(){
	prime[0] = 2;
	memset(isprime, true, sizeof(isprime));

	for(llu i=3; i<=LIM; i+=2){
		if(isprime[i]){
			prime[prime_cont++] = i;
			for(llu j=i*i; j<=LIM; j+=i) 
				isprime[j] = false;
		}
	}
}


int josephusWiki(int n, int k, int i){
	if(n == 1)
		return 0;
	return (josephusWiki(n-1, prime[i], i+1)+k) % n;
}


int main(){
		
	crivo();
	int qtd;

	while(true){
		cin >> qtd;

		if(qtd == 0)
			break;

		
		// int pos = josephus(qtd, 2, 1);
		// int pos = josephusIter(qtd);
		int pos = josephusWiki(qtd, 2, 1) + 1;
		cout << pos << endl;
	}


	return 0;
}


