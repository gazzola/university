#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

// http://mathworld.wolfram.com/KochSnowflake.html
const double C = 0.4330127018922193;
const double K = 1.6;

double area(double l){
	return C*l*l;
}



int main(){

	double l;
	while(scanf("%lf", &l) != EOF){

		/*double s = area(l);
		double k = 3.6;

		for(int i=0; i<30; i++){
			l = l/3.0;
			s += (k*area(l));
			k *= 3;
		}

		printf("%.2lf\n", s);*/

		printf("%.2lf\n", K*area(l));

	}


	return 0;
}