#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}


int main(){

	int t;
	cin >> t;
    
    for(int i=1; i<=t; i+=2)
    	cout << i << endl;

	return 0;
}