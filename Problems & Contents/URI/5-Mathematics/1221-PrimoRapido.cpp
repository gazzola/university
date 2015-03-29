#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


// retirado de: 
// https://thecodeaddict.wordpress.com/2011/10/29/primality-testing/#comments
bool ehPrimo(int x){

	if(x == 2 or x == 3)
		return true;

	if(x % 2 == 0 or x < 2 or x % 3 == 0)
		return false;

	if(x < 9)
		return true;

	int i = 5;
	while(i*i <= x){
		if(x%i == 0 or x%(i+2) == 0)
			return false;
		i += 6;
	}

	return true;
}



int main(){

	int t, n;

	scanf("%d", &t);
	while(t--){
			
		scanf("%d", &n);
		
		if(ehPrimo(n))
			printf("Prime\n");
		else
			printf("Not Prime\n");

	}


	return 0;
}