#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

typedef long long unsigned int llu;

typedef pair<int, int> ii;

typedef struct st{
	int first;
	int second;
	vector<int> nums;

	st(){}
	st(int f, int s, vector<int> t){
		first = f;
		second = s;
		nums = t;
		nums.push_back(f);
	}

}st;



const llu LIM = 10000;
bool isprime[LIM];
vector<int> quais[LIM];
llu prime[LIM];
llu prime_cont = 1;

void crivo(){
	prime[0] = 2;
	memset(isprime, true, sizeof(isprime));

	for(llu i=3; i<=LIM; i+=2){
		if(isprime[i]){
			prime[prime_cont++] = i;
			for(llu j=i*i; j<=LIM; j+=i) 
				isprime[j] = false;
		}
	}
}


const int diff = 1000;
const int tam = 1000000;
bool visitados[tam+diff];
 
int count(int n, int m){

	queue<ii> q;
	q.push(ii(n, 0));


	memset(visitados, false, sizeof(visitados));

	while(true){

		ii x = q.front();
		q.pop();

		if(x.first == m){
			// for(int i=0; i<x.nums.size(); i++)
			//  printf("%d ", x.nums[i]);
			// printf("\n");
			return x.second;
		}


		if(!visitados[diff + x.first/2]){
			visitados[diff + x.first/2] = true;
			q.push(ii(x.first/2, x.second+1));
		}

		if(!visitados[diff + x.first/3]){
			visitados[diff + x.first/3] = true;
			q.push(ii(x.first/3, x.second+1));
		}

		if(diff + x.first-7 >= 0 and !visitados[diff + x.first-7]){
			visitados[diff + x.first-7] = true;
			q.push(ii(x.first-7, x.second+1));
		}

		if(diff + x.first+7 < tam and !visitados[diff + x.first+7]){
			visitados[diff + x.first+7] = true;
			q.push(ii(x.first+7, x.second+1));
		}

		if(diff + x.first*2 < tam and !visitados[diff + x.first*2]){
			visitados[diff + x.first*2] = true;
			q.push(ii(x.first*2, x.second+1));
		}

		if(diff + x.first*3 < tam and !visitados[diff + x.first*3]){
			visitados[diff + x.first*3] = true;
			q.push(ii(x.first*3, x.second+1));
		}


	}

	return 0;
}
 



int main(){

	// crivo();
	

	int a,b;
	scanf("%d %d", &a, &b);
	
	if(a==b)
		printf("0\n");
	else
		printf("%d\n", count(a,b));




	return 0;
}
