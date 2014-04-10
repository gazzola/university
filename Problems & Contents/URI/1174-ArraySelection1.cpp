#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int t=100;
	double x;

	for(int i=0; i<t; i++){
		cin >> x;
		if(x <= 10)
			cout << "A[" << i << "] = " << x << endl; 
	}

	return 0;
}