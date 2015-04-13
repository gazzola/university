#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>

 
using namespace std;

int getNivel(int m){
	if(m < 10)
		return 1;
	if(m < 20)
		return 2;
	return 3;
}


 
int main(){
 
	int l, v, m;

	while(scanf("%d", &l) != EOF){

		m = 1;
		while(l--){
			scanf("%d", &v);
			m = max(m, v);
		}

		printf("%d\n", getNivel(m));
	}
 
 
	return 0;
}