#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	
	int vet[5];
	bool ok;

	while(true){
		
		if(scanf("%d", &vet[0]) == EOF)
			break;

		for(int i=1; i<5; i++)
			scanf("%d", &vet[i]);

		int x;
		for(int i=0; i<5; i++){
			scanf("%d", &x);
			vet[i] += x;
		}

		ok = true;
		for(int i=0; i<5; i++){
			if(vet[i] != 1){
				ok = false;
				break;
			}
		}

		if(ok)
			printf("Y\n");
		else
			printf("N\n");

	}


	
	return 0;
}