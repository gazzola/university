#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

typedef long long unsigned int llu;
typedef long long signed int lls;


int qtos = 0;
lls inf = INT_MAX;
// bool vis[]
lls dp[10001][10001];


lls memo(vector<int> &vet, int p, int q){

	// printf("%d %d\n", p, q);

	if(dp[p][q] == inf){
		if(abs(q-p) <= 1){
			dp[p][q] = vet[p]+vet[q];
			if(dp[p][q] == 0)
				qtos++;
		}
		else{


			int a=p, b=q;
			lls x = memo(vet, p, q-1);
			lls y = memo(vet, p+1, q);
			lls z = (x+y-vet[a]-vet[b])/2;
			
			if(z == 0)
				qtos++;


			dp[p][q] = x+y;
		}
	}

	return dp[p][q];
}




int topdown(vector<int> &vet){

	lls dpb[2][100001];
	int n = vet.size();

	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++){
			if(i == j)
				dpb[i][j] = vet[j];
			else
				dpb[i][j] = 0;
		}
	}


    int qtd = 0;
	for(int i=1; i<n; i++){
		dpb[0][i] = dpb[0][i-1]+vet[i];
		if(dpb[0][i] == 0)
			qtd++;
	}

	for(int i=1; i<n; i++){

		int k = i%2;
		int l = !k;

		for(int j=i; j<n; j++){
			dpb[k][j] = dpb[l][j] - dpb[l][i-1];
			if(dpb[k][j] == 0)
				qtd++;
		}
	}

	return qtd;
}



int main(){

	int n,x;
	vector<int> vet;

	scanf("%d", &n);


	int z = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		
		if(x == 0){
			z++;
		}
		else{
			qtos += (z*(z+1))/2;
			vet.push_back(x);
			z = 0;
		}
	}

	qtos += (z*(z+1))/2;
	n = vet.size();

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dp[i][j] = inf;
	
	int res = memo(vet, 0, n-1);

	// if(n > 0)
		// qtos += topdown(vet);

	printf("%d\n", qtos);

	return 0;
}
