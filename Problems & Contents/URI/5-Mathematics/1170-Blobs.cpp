#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
 
int main(){
 
	int n;
	double x;
 
	scanf("%d", &n);
	while(n--){
		scanf("%lf", &x);
		printf("%d dias\n", (int) ceil(log2(x)));
	}
 
 
	return 0;
}