#include <iostream>
#include <iomanip>
#include <cstdio>
 
using namespace std;
 
 
int main(){
	 
	int t;
	int at, ad ,bt, bd, h;

	scanf("%d", &t);
	while(t--){

		scanf("%d %d %d %d", &at, &ad, &bt, &bd);
		scanf("%d", &h);

		int count = 0;
		bool ganhadorA = true;
		while(true){

			if(count % ad == 0)
				h -= at;

			if(h <= 0){
				ganhadorA = true;
				break;
			}

			if(count % bd == 0)
				h -= bt;

			if(h <= 0){
				ganhadorA = false;
				break;
			}

			count++;
		}

		if(ganhadorA)
			printf("Andre\n");
		else
			printf("Beto\n");


	}
 
	return 0;
}