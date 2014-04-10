#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int x, t=20, v[20];

	for(int i=0; i<20; i++){
		cin >> x;
		v[--t] = x;
	}

	for(int i=0; i<20; i++)
		cout << "N[" << i << "] = " << v[i] << endl; 

	return 0;
}