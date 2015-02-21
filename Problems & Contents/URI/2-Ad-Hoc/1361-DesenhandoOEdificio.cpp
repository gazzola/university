#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
	
	
	int p, n, x, q, diff;
	
	scanf("%d", &p);
	while(p--){

		scanf("%d", &n);

		vector<int> andares;
		for(int i=0; i<n; i++){
			scanf("%d", &x);

			if(x < 0){
				x = abs(x);
				x = x*2;
			}
			else{
				x = abs(x);
				x = x*2 - 1;
			}

			andares.push_back(x);
		}

		sort(andares.begin(), andares.end());

		
		q = andares[n-1] % 2;
		diff = 1;
		
		for(int i=n-2; i>=0; i--){
			if(andares[i]%2 != q){
				q = andares[i] % 2;
				diff++;
			}
		}

		printf("%d\n", diff);

	}

	
	return 0;
}