#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;



int main(){

	
	char rastro[55];
	int p, n;

	while(scanf("%s%n\n%d\n", rastro, &n, &p) != EOF){

		int r = 0;
		int total = 0;

		for(int i=0; i<n; i++){
			if(rastro[i] == 'W'){
				total += ceil(r/(double)p);
				total++;
				r = 0;
			}
			else{
				r++;
			}
		}

		if(rastro[n-1] != 'W')
			total += ceil(r/(double)p);


		printf("%d\n", total);

	}


	return 0;
}