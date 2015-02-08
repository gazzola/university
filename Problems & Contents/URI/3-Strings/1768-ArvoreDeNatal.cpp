#include <cstdio>
#include <string>
#include <cstring>

using namespace std;



int main(){

	int n;
	while(scanf("%d", &n) != EOF){

		int k = (n-1)/2;
		for(int i=1; i<=n; i+=2){

			for(int j=0; j<k; j++)
				printf(" ");

			for(int j=0; j<i; j++)
				printf("*");

			printf("\n");

			k--;
		}

		k = (n-1)/2;
		for(int i=0; i<k; i++)
			printf(" ");
		printf("*\n");

		k--;
		for(int i=0; i<k; i++)
			printf(" ");
		printf("***\n");

		printf("\n");
	}

	return 0;
}