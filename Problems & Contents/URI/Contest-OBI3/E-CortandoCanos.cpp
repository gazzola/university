#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



int main(){
	
	
	int valor[1001], comp[1001], dp[2001];
	int n, m;

	while(scanf("%d %d", &n, &m) != EOF){
		for(int i=0; i<n; i++)
			scanf("%d %d", &comp[i], &valor[i]);

		for(int i=0; i<=m; i++){
			dp[i] = 0;
			for(int j=0; j<n; j++)
				if(comp[j] <= i)
					dp[i] = max(dp[i], dp[i - comp[j]] + valor[j]);
		}

		printf("%d\n", dp[m]);
	}


	return 0;
}
