#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int t=10, x;

	for(int i=0; i<t; i++){
		cin >> x;
		cout << "N[" << i << "] = " << x << endl; 
		x += x;
	}

	return 0;
}