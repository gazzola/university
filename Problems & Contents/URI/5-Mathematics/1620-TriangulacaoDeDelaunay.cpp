#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	double L;
	while(scanf("%lf", &L) and L > 0){
		printf("%.6lf\n", ((L*2 - 3)-L)/L);
	}


	return 0;
}