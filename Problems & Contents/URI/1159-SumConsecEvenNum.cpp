#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int n){
	return ((n & 1) == 0);
}


int main(){

	int x, sum=0;

	while(true){

		cin >> x;

		if(x == 0)
			break;

		x = (isEven(x)) ? x : x+1;

		for(int i=x; i<=x+8; i+=2)
			sum += i;

		cout << sum << endl;
		sum=0;
	}

	return 0;
}