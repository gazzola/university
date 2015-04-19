#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;



// http://i.imgur.com/3ixQKnO.png
double somaCentros(int l, int c, int r1, int r2){

	int cx_1 = r1;
	int cy_1 = c-r1;

	int cx_2 = l-r2;
	int cy_2 = r2;

	int x = cx_2 - cx_1;
	int y = cy_1 - cy_2;

	return sqrt(x*x + y*y);
}


int main(){
		
	int l, c, r1, r2;
	while(scanf("%d %d %d %d", &l, &c, &r1, &r2) and l+c+r1+r2 > 0){

		int m = min(l, c);
		if(2*r1 <= m and 2*r2 <= m and somaCentros(l,c,r1,r2) >= r1+r2)
			printf("S\n");
		else
			printf("N\n");
	}


	return 0;
}