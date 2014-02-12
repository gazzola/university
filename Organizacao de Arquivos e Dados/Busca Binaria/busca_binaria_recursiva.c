#include <stdio.h>
#define MAX 9

int buscaBinaria(int x, int *v, int e, int d) {

	int m;
	if(e <= d){
		m = (e + d)/2;
		if (v[m] == x) return m;
		if (v[m] < x) e = m+1;
		else d = m-1;
		return buscaBinaria(x,v,e,d);
	}
	return -1;
}

int main(){
	
	int v[MAX] = {1,2,3,4,5,6,7,8,9};
	int x;

	x = buscaBinaria(7, v, 0, MAX-1);
	printf("Busca Binaria: %d\n", x);

	return 0;
}