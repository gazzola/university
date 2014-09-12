#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int main(){
 
	unsigned long int n, r1, r2;
	scanf("%lu", &n);
	
	while(n--){
		scanf("%lu %lu", &r1, &r2);
		printf("%lu\n", r1+r2);
	}
 
 
	return 0;
}