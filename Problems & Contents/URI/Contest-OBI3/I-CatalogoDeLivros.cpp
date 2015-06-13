#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;



int ctoi(char c){
	return (int) c - '0'; 
}


bool orderBy(const int &x, const int &y){
	return x > y;
}



int main(){
	
	int m[5][10];
	int n[5], x;

	for(int i=0; i<5; i++){
		scanf("%d", &n[i]);
		for(int j=0; j<n[i]; j++){
			scanf("%d", &x);
			m[i][j] = x;
		}
	}


	vector<int> res;
	for(int i=0; i<n[0]; i++)
		for(int j=0; j<n[1]; j++)
			for(int k=0; k<n[2]; k++)
				for(int l=0; l<n[3]; l++)
					for(int t=0; t<n[4]; t++)
						res.push_back(m[0][i]+m[1][j]+m[2][k]+m[3][l]+m[4][t]);



	sort(res.begin(), res.end(), orderBy);
	scanf("%d", &x);

	long long unsigned int t = 0;
	for(int i=0; i<x; i++)
		t += res[i];

	printf("%llu\n", t);
	

}
