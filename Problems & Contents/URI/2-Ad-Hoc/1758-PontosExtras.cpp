#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;



int main(){

	int t, n, p;
	long double maior[51], maior7[51];
	long double x;
	
	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &p, &n);

		for(int i=0; i<n; i++){

			maior[i] = 0;
			maior7[i] = 0;

			long double media = 0;

			for(int j=0; j<p; j++){
				scanf("%Lf", &x);

				if(x < 7)
					maior7[i] = max(x, maior7[i]);

				maior[i] = max(maior[i], x);
				media += x;
			}

			media = media/p;
		
			if(media < 7){

				// REPROVADO
				if(media < 4)
					printf("%.2Lf\n", media);
				// FINAL
				else{	
					if(maior7[i] > media)
						printf("%.2Lf\n", maior7[i]);
					else
						printf("%.2Lf\n", media);
				}
			}
			// APROVADO
			else
				printf("%.2Lf\n", maior[i]);
		}

	}


	return 0;
}