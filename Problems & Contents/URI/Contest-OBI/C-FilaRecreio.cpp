#include <cstdio>


int proximoMaior(int *notas, int m){

	int maiorPos=1;
	for(int i=1; i<=m; i++)
		if(notas[i] > notas[maiorPos])
			maiorPos = i;

	notas[maiorPos] = -1;
	return maiorPos;
}



int main(){
	
	int n, m, notas[1002], total, maiorPos;

	scanf("%d", &n);	
	while(n--){

		scanf("%d", &m);

		for(int i=1; i<=m; i++)
			scanf("%d", &notas[i]);


		total=0;
		for(int i=1; i<=m; i++){
			maiorPos = proximoMaior(notas, m);
			if(maiorPos == i)
				total++;
		}

		printf("%d\n", total);

	}


	return 0;
}
