#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const double PI = 3.141592654;


int main(){
	
	double a, b, c;
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		a = (a/180)*PI;						// graus para radianos
		double h = b/cos(a);				// cos(a) = adj/hypot
		double res = c + sqrt(h*h - b*b);	// a^2 + b^2 = c^2
		printf("%.2lf\n", res*5);
	}

	return 0;
}