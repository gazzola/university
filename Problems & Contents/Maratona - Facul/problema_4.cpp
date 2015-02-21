#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){


	double notas[] = {100, 50, 20, 10, 5, 2};
	double moedas[] = {1, 0.5, 0.25, 0.10, 0.05, 0.01, 0.01};

	double n, k;
	double diff;

	scanf("%lf %lf", &n, &k);
	diff = k-n;

	int i, j;
	i = j = 0;

	int cnotas[] = {0, 0, 0, 0, 0, 0};
	int cmoedas[] = {0, 0, 0, 0, 0, 0};

	while(true){
		if(notas[i] <= diff){
			cnotas[i]++;
			diff -= notas[i];
		}
		else{
			
			if(i < 6)
				i++;
			else{
				
				if(j == 5){

					int ndiff = diff * 100;
					while(true){
						cmoedas[j]++;
						ndiff -= 1;
						if(ndiff <= 0){
							diff = -1;
							break;
						}
					}
				}
				else{
					if(moedas[j] <= diff){
						cmoedas[j]++;
						diff -= moedas[j];
					}
					else{
						if(j < 6)
							j++;
					}
				}
			}
		}

		
		if(diff <= 0.00)
			break;
	}


	for(int i=0; i<6; i++)
		if(cnotas[i] > 0)
			printf("%d(%d) ", (int)notas[i], cnotas[i]);
	
	printf("\n");

	for(int i=0; i<6; i++)
		if(cmoedas[i] > 0)
			printf("%.0f(%d) ", moedas[i]*100, cmoedas[i]);

	printf("\n");


	return 0;
}