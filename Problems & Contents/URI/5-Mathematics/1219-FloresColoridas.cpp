/*
refs: 
http://www.mathalino.com/reviewer/derivation-of-formulas/derivation-of-formula-for-radius-of-circumcircle
http://mathcentral.uregina.ca/QQ/database/QQ.09.06/s/maria2.html

videos:
https://www.youtube.com/watch?v=5f5ijgPgHIQ
https://www.youtube.com/watch?v=y6fdm0ZXLEE
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

double areaTriangulo(int a, int b, int c){
	double sp = (a+b+c)/2.0;
	return sqrt(sp*(sp-a)*(sp-b)*(sp-c));
}


double areaCirculo(double r){
	return r*r*3.1415926535897;
}


double calcSunflowers(int a, int b, int c){
	double r = (a*b*c)/(4*areaTriangulo(a, b, c));
	return areaCirculo(r);
}


double calcViolets(int a, int b, int c){
	return areaTriangulo(a,b,c);
}


double calcRoses(int a, int b, int c){
	double s = (a+b+c)/2.0;
	double r = areaTriangulo(a,b,c)/s;
	return areaCirculo(r);
}



int main(){
	

	int a, b, c;
	double x, y, z;

	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		
		z = calcRoses(a, b, c);
		y = calcViolets(a, b, c);
		x = calcSunflowers(a, b, c);
		
		printf("%.4lf %.4lf %.4lf\n", x-(y-z)-z, y-z, z);
	}


	return 0;
}