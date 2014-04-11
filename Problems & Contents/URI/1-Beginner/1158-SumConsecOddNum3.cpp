#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}


int main(){

	int n, a, b, sum=0;
	cin >> n;

	while(n--){
		cin >> a >> b;
		
		a = (isOdd(a)) ? a : a+1;

		for(int i=a; i<a+b*2; i+=2)
			sum += i;

		cout << sum << endl;
		sum = 0;
	}

	return 0;
}