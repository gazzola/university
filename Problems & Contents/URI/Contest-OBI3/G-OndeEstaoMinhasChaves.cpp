#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;





int main(){
	
	int q, e, x;
	bool escrit[10000];

	while(scanf("%d %d", &q, &e) != EOF){
		
		memset(escrit, true, sizeof(escrit));

		while(e--){
			scanf("%d", &x);
			escrit[x] = false;
		}

		while(q--){
			scanf("%d", &x);
			printf("%d\n", (int) escrit[x]);
			escrit[x] = false;
		}
	}

	

}
