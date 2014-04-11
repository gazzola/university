#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	double x;
	int t = 100;

	cin >> x;
	cout << fixed << setprecision(4);

	for(int i=0; i<t; i++){
		cout << "N[" << i << "] = " << x << endl; 
		x/=2;
	}

	return 0;
}