#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1002][1002];


// recursive solution
int solve(int *vet, int p, int q){
	if(q-p <= 1){
		if(vet[p] == vet[q])
			return 1;
		return 2;
	}

	if(vet[p] == vet[q])
		return solve(vet, p+1, q-1) + 1;
	
	return min(solve(vet, p+1, q), solve(vet, p, q-1)) + 1;
}


// memoized solution
int memoized(int *vet, int p, int q){
	if(dp[p][q] < 0){
		if(q-p <= 1){
			if(vet[p] == vet[q])
				dp[p][q] = 1;
			else 
				dp[p][q] = 2;
			// dp[p][q] = (int)(vet[p] != vet[q]) + 1;
		}
		else if(vet[p] == vet[q])
			dp[p][q] = memoized(vet, p+1, q-1) + 1;
		else
			dp[p][q] = min(memoized(vet, p+1, q), memoized(vet, p, q-1)) + 1;
	}

	return dp[p][q];
}


int bottomup(int *vet, int n){
	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			if(vet[n-i-1] == vet[j])
				dp[i][j] = dp[i+1][j+1] + 1;
			else
				dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
		}
	}

	return dp[0][0];
}



int main(){

	int vet[10001];
	int t, n, k=1;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &vet[i]);

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dp[i][j] = -1;

		printf("Caso #%d: %d\n", k++, memoized(vet, 0, n-1));
	}

	return 0;
}