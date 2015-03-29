#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int ctoi(char c){
	return (int) c-'0';
}


int main(){
	
	int a, b;
	int base = 10;

	while(scanf("%d %d\n", &a, &b) and (a != 0 or b != 0)){

		int c=0, x=0, p=10;

		if(a < 10 and b < 10){
			if(a+b >= base)
				x++;
		}
		else{
			while(a%p != a or b%p != b){
				int i = (a%p)/(p/10);
				int j = (b%p)/(p/10);

				// printf("%d %d\n", i, j);
				if(i+j+c >= base){
					c = (i+j+c)/base;
					x++;
				}
				else
					c = 0;

				p *= 10;;

			}

			int i = (a%p)/(p/10);
			int j = (b%p)/(p/10);

			// printf("%d %d\n", i, j);
			if(i+j+c >= base){
				c = (i+j+c)/base;
				x++;
			}
		}


		if(x == 0)
			printf("No carry operation.\n");
		else if(x == 1)
			printf("%d carry operation.\n", x);
		else
			printf("%d carry operations.\n", x);

	}

	return 0;
}