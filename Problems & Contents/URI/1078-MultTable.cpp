#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}


int main(){

	int t;
	cin >> t;
	
	for(int i=1; i<=10; i++)
		cout << i << " x " << t << " = " << i*t << endl;
	

	return 0;
}