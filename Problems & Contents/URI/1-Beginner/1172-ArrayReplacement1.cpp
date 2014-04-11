#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int t=10, x;

	for(int i=0; i<t; i++){
		cin >> x;
		x = (x < 1) ? 1 : x;
		cout << "X[" << i << "] = " << x << endl; 
	}

	return 0;
}