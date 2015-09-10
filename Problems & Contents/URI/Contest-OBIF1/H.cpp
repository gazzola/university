#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;



int dp[10001][10001];
bool vis[10001][10001];
int qtos = 0;
int inf = -99;



int sum(vector<int> &vet, int p, int q){
	int s = 0;
	for(int i=p; i<=q; i++)
		s += vet[i];
	return s;
}



int memo(vector<int> &vet, int p, int q){

	printf("%d %d\n", p, q);

	if(dp[p][q] == inf){
		if(abs(q-p) <= 1){
			dp[p][q] = vet[p]+vet[q];
			if(dp[p][q] == 0)
				qtos++;
		}
		else{

			int z = 0;
			if(q-p > 0)
				z = memo(vet, q-1, p+1);

			int x = memo(vet, p, q-1);
			int y = memo(vet, p+1, q);

			

			if(x+y-z == 0 and !vis[p][q]){
				printf("+++[%d, %d]: %d,%d\n", p, q, x, y);
				qtos++;
			}


			dp[p][q] = x+y;
		}
	}

	vis[p][q] = true;
	return dp[p][q];
}




int bottom(vector<int> &vet, int p, int q){

	int n = vet.size();
	int dp[2][100000];

	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++){
			if(i == j)
				dp[i][j] = vet[j];
			else
				dp[i][j] = 0;
		}
	}


	int s = dp[0][0];
	int qtd = (s == 0);
	for(int i=1; i<n; i++){
		dp[0][i] = dp[0][i-1]+vet[i];
		if(dp[0][i] == 0)
			qtd++;
	}


	for(int i=1; i<n; i++){

		int k = i%2;
		int l = !k;

		for(int j=i; j<n; j++){
			dp[k][j] = dp[l][j] - dp[l][i-1];
			if(dp[k][j] == 0)
				qtd++;
		}
	}

	return qtd;
}



int main(){

	int n,x;
	vector<int> vet;

	scanf("%d", &n);

	int s = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		vet.push_back(x);
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dp[i][j] = inf;
			vis[i][j] = false;
		}
	}


	int res = memo(vet, 0, n-1);
	printf("%d\n", qtos);

	

	return 0;
}
