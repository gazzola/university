#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;


int main(){
	
	
	int n, vet[51];
	long long unsigned int s;

	while(scanf("%d", &n) and n > 0){
		for(int i=0; i<n; i++)
			scanf("%d", &vet[i]);

		s = 0;
		for(int i=n-1; i>=0; i--)
			s += vet[i]+s;

		printf("%llu\n", s);
	}


	return 0;
}