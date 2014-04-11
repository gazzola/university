#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int *n){
	return (((*n) & 1) == 0);
}

int main(){

	int t, x, sum;
	bool prime;
	cin >> t;

	while(t--){

		cin >> x;
		prime = true;

		if(isEven(&x)){
			if(x == 2) //dont forget: 2 is a prime number :X
				cout << x << " eh primo" << endl;
			else
				cout << x << " nao eh primo" << endl;
		}
		else{

			for(int i=2; i<=(x/2)+1; i++){
				if(x % i == 0){
					prime = false;
					break;
				}
			}

			if(prime)
				cout << x << " eh primo" << endl;
			else
				cout << x << " nao eh primo" << endl;
		}
	}

	return 0;
}