#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	const int da = 12;
	int d, vf, vg;


	while(scanf("%d %d %d", &d, &vf, &vg) != EOF){

		double c = sqrt(da*da + d*d);
		if(da/(double) vf >= c/(double) vg)
			printf("S\n");
		else
			printf("N\n");
	}


	return 0;
}