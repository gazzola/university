#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	int lajotas[41], n;
	
	lajotas[0] = lajotas[1] = 1;
	for(int i=2; i<41; i++)
		lajotas[i] = lajotas[i-1]+lajotas[i-2];

	while(scanf("%d", &n) and n > 0){
		printf("%d\n", lajotas[n]);
	}


	return 0;
}