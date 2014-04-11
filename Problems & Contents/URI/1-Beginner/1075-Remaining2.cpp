#include <iostream>
using namespace std;


int main(){

	int t, x;
	cin >> t;

	if(t < 0)
		t = -t;

	x = (t > 2) ? 0 : -1;

	for(int i=x+2; i<50; i+=t)
		cout << i << endl;


	return 0;
}