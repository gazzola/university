#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	

	int n, x, i;
	int *totais = new int[10000000];

	while(scanf("%d", &n) != EOF){

		vector<int> pontos;
		int sum = 0;

		for(i=0; i<n; i++){
			scanf("%d", &x);
			pontos.push_back(sum);
			sum += x;
		}

		if(sum % 3 != 0){
			printf("0\n");
			continue;
		}

		int dist = sum/3;
		for(int i=0; i<dist; i++)
			totais[i] = 0;

		int count = 0;
		for(int i=0; i<(int) pontos.size(); i++){
			int pos = pontos[i]%dist;
			totais[pos]++;
			if(totais[pos] % 3 == 0)
				count++;
		}

		
		printf("%d\n", count);
	}

	delete[] totais;
	
	return 0;
}