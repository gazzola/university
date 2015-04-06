#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int mdc(int a, int b){
	int temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}
	return temp;
}

int mmc(int a, int b){
	return abs(a*b)/mdc(a, b);
}


int main(){

	int n, a, b;
	while(scanf("%d %d %d", &n, &a, &b) and a+b+n > 0){

		int da = n/a;
		int db = n/b;
		int dx = n/mmc(a, b);

		printf("%d\n", da + db - dx); 
	}
	

	return 0;
}