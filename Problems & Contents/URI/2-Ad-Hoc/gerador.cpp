#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	//int k = 1000;

	//while(k--){

		/*int y = (rand()%10)+2;
		int x = (rand()%(20-y))+y;
		
		printf("%d %d\n", x, y);*/

		for(int i=2; i<=60; i++){
			for(int j=i; j>=2; j--){
				printf("%d %d\n", i, j);
			}
		}

	//}

	printf("0 0\n");

	return 0;
}

