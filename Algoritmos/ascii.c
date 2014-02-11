/*
* Imprimir caracteres ascii
*/

#include <stdio.h>
#define LINHA 16

int main() {
	int c;
	for(c = 0;c < 256;c++) {
		if (c % LINHA == 0) 
			printf ("\n %3d: ", c);
		if(c < 32 || (c > 127 && c < 192)) 
			printf(". ");
		else
			printf("%c ",c);
	}
	printf("\n\n");

	return 0;
}
