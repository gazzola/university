#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	

	int h, m, s, t, aux, last=0;

	char c;
	double total = 0;
	double v = 0;

	while(scanf("%d:%d:%d%c", &h, &m, &s, &c) != EOF){
		
		t = 3600*h + m*60 + s;
		aux = t-last;
		total += (v*aux)/3600.0;

		if(c == ' ')
			scanf("%lf", &v);
		else
			printf("%.2d:%.2d:%.2d %.2lf km\n", h, m, s, total);

		last = t;
	}


	return 0;
}