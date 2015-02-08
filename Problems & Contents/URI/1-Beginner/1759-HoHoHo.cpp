#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int main(){
 
	int n;
	scanf("%d", &n);

	if(n > 1){
		printf("Ho");
		for(int i=1; i<n; i++)
			printf(" Ho");
		printf("!\n");
	}
	else if(n == 1)
		printf("Ho!\n");
	else
		printf("\n");
 
 
	return 0;
}