#include <stdio.h>

int main(void) {
	int i,j,k;
	
	printf("J: ");
	scanf("%d", &j);
	k = (j+13)/27;

	while(k<=10){
		k += 1;
		i = 3*k - 1;
	}

	printf("%d\n%d\n", k, i);

	return 0;
}