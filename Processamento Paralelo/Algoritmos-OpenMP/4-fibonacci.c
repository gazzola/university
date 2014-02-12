#include<stdio.h>
#include<stdlib.h>

int fib( int n ){ 
  if( n < 2 )   
    return n; 
  else{ 
    int x, y; 
    x = fib( n-1 ); 
    y = fib( n-2 ); 
    return( x + y ); 
  } 
}

int main (int argc, char **argv){
	int result, n;

	printf("Programa calcula enesimo numero da sequencia de fibonacci.\n\nEntre com o valor de N:\n");
	scanf("%d", &n);

	result = fib(n);

	printf("O %d-esimo numero da sequencia de fibonacci: %d\n", n, result);
	
	return 1;
}
