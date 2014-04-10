#include <iostream>
#include <iomanip>

using namespace std;

int max(int *a, int *b){
	return (*a > *b) ? *a : *b;
}

int min(int *a, int *b){
	return (*a < *b) ? *a : *b;
}

int main(){

	int a, b, init, final;

	cin >> a >> b;

	init = min(&a, &b);
	final = max(&a, &b);

	for(int i=init+1; i<final; i++)
		if((i%5) == 2 || (i%5) == 3)
			cout << i << endl;

	return 0;
}