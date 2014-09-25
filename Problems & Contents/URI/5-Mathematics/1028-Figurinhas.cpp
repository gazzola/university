#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int mdc(int a, int b){
	int temp;
	while(a != 0){
		temp = a;
		a = b%a;
		b = temp;
	}

	return temp;
}

// binary gcd
int gcd(int a, int b){
	while(b) 
		b ^= a ^= b ^= a %= b;
	return a;
}


using namespace std;

int main(){

	int n, a, b;
	scanf("%d", &n);

	while(n--){
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}


	return 0;
}