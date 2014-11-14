#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


double probPulos(int n, int k){
	
	int t = 0;
	
	int j = 1;
	if(k%2 == 1)
		j = 2;
	
	for(int i=1; i<=n; i+=j){
		if(k%i == 0)
			++t;
		else if(i > k)
			break;
	}

	return (double) t/n;
}

 
int main(){
 
	int t, n, k;

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		printf("%.12lf\n", probPulos(n, k));
	}
 
	return 0;
}