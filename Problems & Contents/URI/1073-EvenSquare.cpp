#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}


int main(){

	int t;
	cin >> t;
    
    for(int i=2; i<=t; i+=2)
    	cout << i << "^2 = " << i*i << endl;

	return 0;
}