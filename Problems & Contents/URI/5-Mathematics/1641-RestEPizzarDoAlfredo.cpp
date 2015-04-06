#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;


int main(){
	
	int r, w, l, k=1;
	double d;

	while(scanf("%d", &r) and r > 0){
		scanf("%d %d", &w, &l);
		
		d = sqrt(w*w + l*l);
		if(2*r >= d)
			printf("Pizza %d fits on the table.\n", k++);
		else
			printf("Pizza %d does not fit on the table.\n", k++);
	}


	return 0;
}