#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	unsigned int a, b, result;
	while(cin >> a >> b){

		result = a ^ b;
		cout << result << endl;

	}

	return 0;
}