#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;



int main(){

	int a, b, i=1;
	const int c = 26;


	while(scanf("%d %d", &a, &b) and a > 0 and b > 0){
		int x = ceil(a/(double) b)-1;
		if(x <= c)
			printf("Case %d: %d\n", i++, x);
		else
			printf("Case %d: impossible\n", i++);
	}


	return 0;
}