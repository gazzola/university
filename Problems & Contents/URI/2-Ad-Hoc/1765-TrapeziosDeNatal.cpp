#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const double H = 5.0;

double area(double a, double b){
	return (H*(a+b))/2.0;
}



int main(){
	
	int t, q;
	double a, b;
	

	while(scanf("%d", &t) and t > 0){
		for(int i=1; i<=t; i++){
			scanf("%d %lf %lf", &q, &a, &b);
			printf("Size #%d:\n", i);
			printf("Ice Cream Used: %.2lf cm2\n", q*area(a, b));
		}
		printf("\n");
	}

	
	return 0;
}