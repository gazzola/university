#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}


int main(){

	int t;
	cin >> t;
    
	t = (isOdd(t)) ? t : t+1;

    for(int i=t; i<=t+11; i+=2)
    	cout << i << endl;

	return 0;
}