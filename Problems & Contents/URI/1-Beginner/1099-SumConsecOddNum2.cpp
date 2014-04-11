#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}

int max(int *a, int *b){
	return (*a > *b) ? *a : *b;
}

int min(int *a, int *b){
	return (*a < *b) ? *a : *b;
}


int main(){

	int n, a, b, init, final, sum=0;
	cin >> n;

	while(n--){
		cin >> a >> b;
		
		init = (isOdd(min(&a, &b))) ? min(&a, &b)+2 : min(&a, &b)+1;
		final = max(&a, &b);

	    for(int i=init; i<final; i+=2)
	    	sum += i;

	    cout << sum << endl;
	    sum = 0;
	}

	return 0;
}