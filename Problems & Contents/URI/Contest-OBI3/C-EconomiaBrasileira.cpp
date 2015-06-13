#include <cstdio>
#include <cmath>


int main(){
	
	int n, x, m=0;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		m += (x == 0) ? 1 : 0;
	}

	if(2*m > n)
		printf("Y\n");
	else
		printf("N\n");

}
