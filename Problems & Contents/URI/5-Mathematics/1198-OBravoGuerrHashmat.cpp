#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
 
int main(){
 
	long long int a, b;
	while(scanf("%lld %lld", &a, &b) != EOF){
		printf("%lld\n", abs(b-a));
	}
 
 
	return 0;
}