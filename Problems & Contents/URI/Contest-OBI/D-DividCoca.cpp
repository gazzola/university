#include <cstdio>
#include <cmath>

int main(){
	
	const double PI = 3.141592654;
	int casos;
	double b, B, H, N, L, result;

	scanf("%d", &casos);
	while(casos--){

		scanf("%lf %lf", &N, &L);
		scanf("%lf %lf %lf", &b, &B, &H);

		if(B == b) //cilindro
			result = L/(N*PI*b*b);
		else //tronco cone
			result = (pow((((H*H)*(H*N*PI*b*b*b - 3.0*L*b + 3.0*B*L)) / (N*pow((B-b), 3.0))), 1.0/3) / (pow(PI, 1.0/3))) - (H*b)/(B-b);
		
		printf("%.2lf\n", result);
	}


	return 0;
}
