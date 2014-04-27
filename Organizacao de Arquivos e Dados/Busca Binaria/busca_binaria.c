#include <stdio.h>
#define MAX 29

int buscaBinaria(int x, int *v) {
	int e=0, m, d=MAX-1, count=0;
 
   while (e <= d) { 
      m = (e + d)/2; 
      if (v[m] == x) return count;
      if (v[m] < x) e = m + 1;
      else d = m - 1;
   }

	return -1;
}

int buscaBinariaRec(int x, int *v, int e, int d, int count) {

	int m;
	if(e <= d){
		m = (e + d)/2;
		count++;
		if (v[m] == x) return count;
		if (v[m] < x) e = m+1;
		else d = m-1;
		return buscaBinariaRec(x,v,e,d, count);
	}
	return -1;
}

int buscaSequencial(int x, int *v){
	int i;
	for(i=0; i<MAX; i++){
		if(v[i] == x) 
			return i;	
	}
	return -1;
}

int main(){
	
	int v[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	int x1, x2, x3;

	x1 = buscaBinaria(6, v);
	x2 = buscaBinariaRec(6, v, 0, MAX-1, 0);
	x3 = buscaSequencial(6, v);
	
	printf("Iteracoes Busca Binaria: %d\n", x1);
	printf("Iteracoes Busca Binaria Recursiva: %d\n", x2);
	printf("Iteracoes Busca Sequencial: %d\n", x3);

	return 0;
}