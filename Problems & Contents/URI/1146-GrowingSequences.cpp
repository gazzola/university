#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int i, x;

	while(true){
		cin >> x;

		if(x==0)
			break;

		for(i=1; i<x; i++)
			cout << i << " ";
		cout << i << endl;
	}

	return 0;
}