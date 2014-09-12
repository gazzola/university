#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;



int main(){
	

	int n, x;

	scanf("%d", &n);
	while(n--){

		scanf("%d", &x);
		printf("%d\n", (int) round(x/2.0));

	}

	return 0;
}