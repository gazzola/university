#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int t = 1000;
	int a, b, c;

	while(t--){	
		a = (rand()%13)+1;
		b = (rand()%13)+1;
		c = (rand()%13)+1;
		printf("%d %d %d\n", a, b, c);
	}

	printf("0 0 0\n");


	return 0;
}

