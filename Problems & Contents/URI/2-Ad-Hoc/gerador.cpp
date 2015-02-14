#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int t = 1000;
	printf("%d\n", t);
	while(t--){

		int n, p;
		
		n = (rand()%49)+2;
		p = (rand()%4)+2;

		printf("%d %d\n", p, n);
		
		while(n--){
			float r = (float)(rand()%10) / (float)10;
			printf("%.1f", r);
			for(int i=1; i<p; i++){
				r = (float)rand()/(float)(RAND_MAX/10);
				printf(" %.1f", r);
			}
			printf("\n");
		}

	}


	return 0;
}

