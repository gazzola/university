#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef struct coef{
	int a,b,c,d,t;
}coef;



int main(){
	
	int m, n;
	int x, y, z;

	coef planos[501];

	while(scanf("%d %d", &m, &n) != EOF){

		for(int i=0; i<m; i++){
			planos[i].t = 0;
			scanf("%d %d %d %d", &planos[i].a, &planos[i].b, &planos[i].c, &planos[i].d);
		}

		map<string, int> dict;
		int maior = 0;

		for(int i=0; i<n; i++){
			scanf("%d %d %d", &x, &y, &z);

			string s;
			for(int j=0; j<m; j++){

				int a = planos[j].a;
				int b = planos[j].b;
				int c = planos[j].c;
				int d = planos[j].d;

				if(a*x + b*y + c*z > d)
					s.push_back('y');
				else
					s.push_back('n');
			}

			dict[s] += 1;
			maior = max(maior, dict[s]);
		}

		printf("%d\n", maior);

	}

	
	return 0;
}