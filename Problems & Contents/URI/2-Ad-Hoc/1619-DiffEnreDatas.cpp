#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

// Rata Die day one is 0001-01-01
int rdn(int y, int m, int d){
	if (m < 3){
		y--;
		m += 12;
	}

	return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

int main(){
	

	int n;
	scanf("%d", &n);

	int a1, m1, d1;
	int a2, m2, d2;

	while(n--){

		scanf("%d-%d-%d %d-%d-%d", &a1, &m1, &d1, &a2, &m2, &d2);

		int days = rdn(a1, m1, d1) - rdn(a2, m2, d2);
		printf("%d\n", abs(days));
	}

	
	return 0;
}