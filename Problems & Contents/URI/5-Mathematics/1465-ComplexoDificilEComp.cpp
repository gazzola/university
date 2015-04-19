#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>

using namespace std;


int main(){
	
	int t;
	double x, y;
	complex<double> i;

	scanf("%d", &t);
	while(t--){

		
		scanf("%lf %lf", &x, &y);
		
		i = -1;
		i = x + y * sqrt(i);
		
		if(y == 0){
			printf("1\n");
			continue;
		}

		i = i*i;
		if(imag(i) == 0){
			printf("2\n");
			continue;
		}

		i = i*i;
		if(imag(i) == 0){
			printf("4\n");
			continue;
		}

		printf("TOO COMPLICATED\n");
	}

	return 0;
}