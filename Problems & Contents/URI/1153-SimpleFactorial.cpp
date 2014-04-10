#include <iostream>
#include <iomanip>

using namespace std;


void normal(int n){

	long int t=1;

	for(int i=1; i<=n; i++)
		t *= i;
		
	cout << t << endl;
}


void apelar(int n){
	long int fac[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
    cout << fac[n] << endl;
}


int main(){

	int n;
	cin >> n;

	apelar(n);	

	return 0;
}