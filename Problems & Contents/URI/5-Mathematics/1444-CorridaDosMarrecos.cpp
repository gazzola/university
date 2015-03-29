#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;




int main(){

	
	int passos[100001];
	passos[0] = passos[1] = 0;
	passos[2] = passos[3] = 1;
	passos[4] = passos[5] = passos[6] = 3;

	for(int i=7; i<100001; i++){
		int j = i/3;
		int k = (i%3) == 0 ? 0 : 1;
		passos[i] = j+k+passos[j+k];
	}

	int n;
	while(scanf("%d", &n) and n > 0){
		printf("%d\n", passos[n]);
	}


	return 0;
}