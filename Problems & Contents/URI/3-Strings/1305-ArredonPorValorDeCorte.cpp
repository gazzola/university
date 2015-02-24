#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;



int main(){

	long double num, cutoff, frac;

	while(scanf("%Lf\n%Lf\n", &num, &cutoff) != EOF){

		frac = num - (int) num;

		if(cutoff >= frac)
			printf("%d\n", (int) floor(num)); 
		else
			printf("%d\n", (int) ceil(num)); 
	}


	return 0;
}