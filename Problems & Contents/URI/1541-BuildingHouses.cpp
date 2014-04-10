#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){

	int result, a, b, c;

	while(true){

		cin >> a >> b >> c;
		
		if(a == 0)
			break;
	
		result = sqrt(((a*b)*100)/double(c));
		cout << result << endl;

	}

	return 0;
}