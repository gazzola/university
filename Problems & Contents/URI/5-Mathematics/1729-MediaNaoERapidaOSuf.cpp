#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	int n, t, m, s, h;
	char x, aux[1000];
	double d;

	scanf("%d %lf", &n, &d);
	while(scanf("%d ", &t) != EOF){

		int soma = 0;
		bool desistiu = false;
		for(int i=0; i<n; i++){
			scanf("%c:%d:%d ", &x, &m, &s);
			if(x == '-'){
				scanf("%[^\n]\n", aux);
				desistiu = true;
				break;
			}

			h = x-'0';
			soma += h*3600 + m*60 + s;
		}

		double media = soma/d;
		if(!desistiu){
			
			printf("%3d: ", t);
			int mins = (int) media/60.0;
			int secs = (int) round(media - mins*60);

			if(mins >= 1)
				if(secs > 59)
					printf("%d:", mins+1);
				else
					printf("%d:", mins);
			else
				printf("  0:");

			if(secs > 59)
				printf("00 min/km\n");
			else
				printf("%.2d min/km\n", secs);
		}
		else
			printf("%3d: -\n", t);
	}
	

	return 0;
}