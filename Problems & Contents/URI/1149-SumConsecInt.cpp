#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int a, n, sum=0;

	cin >> a;

	while(true){
		cin >> n;
		if(n > 0)
			break;
	}

	for(int i=a; i<a+n; i++)
		sum += i;

	cout << sum << endl;

	return 0;
}