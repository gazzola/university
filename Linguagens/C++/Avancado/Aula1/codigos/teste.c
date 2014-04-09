#include <stdio.h>

int main() {
	int y, *p, x;
	y = 0;

	p = &y;
	printf ("*p = %d\n", (*p));
	
	x = *p;
	printf ("x = %d\n", x);
	x = 4;
	
	(*p)++;
	x--;
	printf ("x = %d\n", x);
	printf ("*p = %d\n", (*p));

	(*p) += x;
	printf ("x = %d\n", x);
	printf ("*p = %d\n", (*p));

	return 0;
}