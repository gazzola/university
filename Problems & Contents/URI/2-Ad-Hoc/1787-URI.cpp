#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int max3(int a, int b, int c){
	if(a >= b and a >= c)
		return a;

	if(b >= a and b >= c)
		return b;

	return c;
}


bool ehP2(int x){
	if(x < 2)
		return false;
	return ((x & (~x + 1)) == x);
}



int main(){
	
	int n, u, r, i, m;
	int pu, pr, pi;

	while(scanf("%d", &n) and n > 0){

		pu = pr = pi = 0;
		while(n--){
			scanf("%d %d %d", &u, &r, &i);

			m = max3(u, r, i);

			if(ehP2(u)){
				pu++;
				if(m == u)
					pu++;
			}
			
			if(ehP2(r)){
				pr++;
				if(m == r)
					pr++;
			}

			if(ehP2(i)){
				pi++;
				if(m == i)
					pi++;
			}
		}


		if(pu > pr and pu > pi)
			printf("Uilton\n");
		else if(pr > pu and pr > pi)
			printf("Rita\n");
		else if(pi > pu and pi > pr)
			printf("Ingred\n");
		else
			printf("URI\n");

	}

	
	return 0;
}