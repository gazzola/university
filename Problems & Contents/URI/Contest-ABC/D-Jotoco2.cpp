#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);

	double x = 0;
	int dias = 0;
	while(x < b){
		x += a;
		if(x > b){
			dias++;
			break;
		}
		x -= x/10.0;
		dias++;
	}

	printf("%d\n", dias);
}