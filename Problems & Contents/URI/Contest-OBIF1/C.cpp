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



int main(){

	int n, t, l, s;
	scanf("%d %d %d", &n, &t, &l);
	
	int i = 0;
	int v[2] = {0, 0};

	while(--n){

		scanf("%d", &s);
		if(abs(t-s) <= l){
			v[i] += abs(t-s);
			t = s;
		}

		i = !i;
	}

	printf("%d %d\n", v[0], v[1]);


	return 0;
}
