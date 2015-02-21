#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortThreeValues(int *x, int *y, int *z){
	if(*x > *y)
		swap(&(*x), &(*y));

	if(*y > *z)
		swap(&(*y), &(*z));

	if(*x > *y)
		swap(&(*x), &(*y));
}


int main(){
	
	
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) and a > 0){


		if(a == b and b == c){
			if(a < 13)
				printf("%d %d %d\n", a+1, b+1, c+1);
			else
				printf("*\n");
		}
		else if(a == b or a == c or b == c){

			sortThreeValues(&a, &b, &c);
			
			if(a == b){
				if(c+1 > 13){
					if(a == 13)
						printf("1 1 1\n");
					else
						printf("1 %d %d\n", a+1, b+1);
				}
				else{
					c++;
					if(c == b)
						c++;
					printf("%d %d %d\n", a, b, c);
				}
			
			}
			else{
				if(a+1 >= 13)
					printf("1 1 1\n");
				else{
					a++;
					if(a == b)
						printf("%d %d %d\n", b, c, a+1);
					else
						printf("%d %d %d\n", a, b, c);
					
				}

			}
		}
		else{
			printf("1 1 2\n");
		}


	}


	
	return 0;
}