#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int a, b, c;

	while(cin >> a >> b >> c){
		if((a == 0 && b == 0 && c == 0) || (a == 1 && b == 1 && c == 1))
			cout << "*" << endl;
		else if((a == 1 && b == 1) || (a == 0 && b == 0))
			cout << "C" << endl;
		else if((b == 1 && c == 1) || (b == 0 && c == 0))
			cout << "A" << endl;
		else if((a == 1 && c == 1) || (a == 0 && c == 0))
			cout << "B" << endl;
	}

	return 0;
}