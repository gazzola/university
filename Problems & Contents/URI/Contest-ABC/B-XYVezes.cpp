#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", a);
	for(int i=1; i<b; i++){
		a *= 10;
		printf(" %d", a);
	}

	printf("\n");
}


