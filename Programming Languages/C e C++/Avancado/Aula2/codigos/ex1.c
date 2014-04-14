#include <stdio.h>

#define min(a,b) (a<b) ? a : b
#define isPar(a) (a & 1) ? 0 : 1

int main(){

	printf("MIN(2,5): %d\n", min(2,5));
	printf("MIN(6,3): %d\n", min(6,3));

	printf("PAR(5): %d\n", isPar(5));
	printf("PAR(8): %d\n", isPar(8));

	return 0;
}