#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){
	
	int n, a, b;

	cin >> n;

	while(n--){

		cin >> a >> b;
		

		int x = a-2;
		int y = b-2;


		int val = ceil(double(x)/3) * ceil(double(y)/3);
		cout << val << endl;

	}

	return 0;
}