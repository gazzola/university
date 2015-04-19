#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;



int main(){
	
	const int fat[5] = {1, 2, 6, 24, 120};
	int n, x, i;

	while(scanf("%d", &n) and n > 0){

		x = i = 0;
		while(n > 0){
			x += (n%10)*fat[i++];
			n /= 10;
		}

		printf("%d\n", x);
	}

	return 0;
}