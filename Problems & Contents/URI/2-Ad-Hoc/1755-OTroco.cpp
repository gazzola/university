#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	
	int t, d, n;
	int pi[301];
	double x;

	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &d, &n);
		for(int i=0; i<n; i++){
			scanf("%lf", &x);
			pi[i] = round(x*100);
		}

		d *= 100;
		int maior = 0;
		for(int i=0; i<n; i++)
			if(pi[i] <= d)
				maior = max(maior, d%pi[i]);

		printf("%.2lf\n", maior/100.0);

	}

	
	return 0;
}