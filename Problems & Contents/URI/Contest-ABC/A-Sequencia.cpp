#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);

	for(int i=min(a,b); i<=max(a,b); i++)
		printf("%d ", i);
	printf("\n");
}


