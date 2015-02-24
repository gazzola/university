#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


typedef long long unsigned int llu;


int numDigits(int n){
	if(n == 0)
		return 1;
	return (int) log10(n) + 1;
}



int getExponent(int d){
	if(d <= 3)
		return 0;

	if(d <= 6)
		return 3;

	if(d <= 9)
		return 6;

	return 9;
}



int main(){

	
	llu dolar;
	int cent;
	while(scanf("%llu\n%d", &dolar, &cent) != EOF){


		int d = numDigits(dolar);
		int k = 0;

		printf("$");
		llu e = pow(10, getExponent(d));

		bool first = true;
		while(k < d){

			int frac = dolar / e;

			if(first)
				printf("%d", frac);
			else
				printf(",%.3d", frac);
			
			dolar %= e;
			e /= 1000;
			k += 3;
			
			first = false;
		}

		printf(".%.2d\n", cent);


	}


	return 0;
}