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

	int a, b, sum=0, init, final;

	cin >> a >> b;

	init = min(&a, &b);
	final = max(&a, &b);

	for(int i=init; i<=final; i++)
		if(i % 13)
			sum += i;

	cout << sum << endl;

	return 0;
}