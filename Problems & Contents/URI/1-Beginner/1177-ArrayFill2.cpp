#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int t=1000, x, j=0;
	cin >> x;

	for(int i=0; i<t; i++){
		cout << "N[" << i << "] = " << j << endl; 
		
		j++;
		if(j == x)
			j=0;
	}

	return 0;
}