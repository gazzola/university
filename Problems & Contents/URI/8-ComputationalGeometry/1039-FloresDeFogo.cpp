#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 99999999;


int main(){
		
	int r1, x1, y1, r2, x2, y2;

	while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF){

		int dx = x1-x2;
		int dy = y1-y2;
		double dxy = sqrt(dx*dx + dy*dy);
		
		if(dxy+r2 <= r1)
			printf("RICO\n");
		else
			printf("MORTO\n");
	}



	return 0;
}