#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){
	
	int a, b, x;
	int alice[100002], beatriz[100002];

	while(true){

		scanf("%d %d ", &a, &b);
		if(a == 0 && b == 0)
			break;

		memset(alice, 0, sizeof(alice));
		memset(beatriz, 0, sizeof(beatriz));


		int countAlice = 0;
		for(int i=0; i<a; i++){
			scanf("%d ", &x);

			if(alice[x] == 0){
				alice[x] = 1;
				countAlice++;
			}
		}


		int countBeatriz = 0, countIguais=0;
		for(int i=0; i<b; i++){
			scanf("%d ", &x);
			if(beatriz[x] == 0){
				beatriz[x] = 1;
				countBeatriz++;
			
				if(alice[x] == 1)
					countIguais++;
			}
		}

		countIguais = (countAlice < countBeatriz) ? countAlice-countIguais : countBeatriz-countIguais; 
		printf("%d\n", countIguais);

	}

	return 0;
}

