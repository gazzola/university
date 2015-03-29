#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
int numDigits(long long int n){
	if(n == 0)
		return 1;
	return (int) log10(n) + 1;
}
 
 
int main(){
 
	int n;
	long long int a, b;
 
	scanf("%d\n", &n);
	while(n--){
		scanf("%lld %lld", &a, &b);
 
		if(a == b)
			printf("encaixa\n");
		else{
			int d = numDigits(b);
			if(a % (long long int) pow(10, d) == b)
				printf("encaixa\n");
			else
				printf("nao encaixa\n");
		}
		 
	}
 
 
	return 0;
}