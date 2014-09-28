#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

int paraCubo(int a, int b, int c){

	int ap = a*b*c;
	int i;
	int x = min(a, b);
	x = min(x, c);

	for(i=x; i<1000; i++){
		int ac = (i*i*i);
		if(ac > ap)
			break;
	}

	return i-1;
}



int main(){

	
	int a, b, c;
	while(true){

		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 and b == 0 and c == 0)
			break;

		int res = paraCubo(a, b, c);
		printf("%d\n", res);
	}



	return 0;
}