#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int a, b, i;
	cin >> a >> b;

	for(i=1; i<=b; i++){
		if(i % a == 0)
			cout << i << endl;
		else
			cout << i << " ";
	}

	return 0;
}