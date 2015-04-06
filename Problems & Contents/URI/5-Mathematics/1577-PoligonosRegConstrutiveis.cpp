#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int fermatPrimes[5] = {3, 5, 17, 257, 65537};

bool ehPotenciaDe2(int x){
	if(x < 2)
		return false;
	return ((x & (~x + 1)) == x);
}

bool ehPoligonoRegConstrutivel(int n){

	if(ehPotenciaDe2(n))
		return true;
	
	while(n%2 == 0)
		n /= 2;

	if(n == 1)
		return true;

	int k, j;
	for(int i=0; i<5; i++){
		
		k = fermatPrimes[i];
		j = 0;

		while(n % k == 0){
			j++;
			n /= k;
		}
		
		if(j > 1)
			return false;
		else if(n == 1)
			return true;
	}

	return n == 1;
}


int main(){
	
	int t, n;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(ehPoligonoRegConstrutivel(n))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}