#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

// retirade de: http://codeforces.com/blog/entry/13713
int kadanes(vector<int> a){
	int max_so_far = a[0];
	int curr_max = a[0];

	for(int i=1; i<(int) a.size(); i++){
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}


int main(){
	
	int n, x;
	vector<int> mudanca;


	scanf("%d", &n);

	int ant = -1;
	while(n--){
		scanf("%d", &x);
		if(ant >= 0)
			mudanca.push_back(x - ant);
		ant = x;
	}

	int res = kadanes(mudanca);
	printf("%d\n", (res < 0) ? 0 : res);

	
}

