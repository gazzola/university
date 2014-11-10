#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int t = 100000;
	while(t--){
		int x = (rand()%100000)+1;
		printf("%d\n", x);
	}


	return 0;
}

