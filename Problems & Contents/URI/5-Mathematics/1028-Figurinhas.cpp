#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int mdc(int a, int b){
	int temp;
	while(a != 0){
		temp = a;
		a = b%a;
		b = temp;
	}

	return temp;
}


using namespace std;

int main(){

	int n, a, b;
	scanf("%d", &n);

	while(n--){
		scanf("%d %d", &a, &b);
		if(a == b)
			printf("%d\n", a);
		else
			printf("%d\n", mdc(a, b));
	}


	return 0;
}