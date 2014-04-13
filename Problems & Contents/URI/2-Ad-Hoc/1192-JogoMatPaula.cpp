#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


int main(){
	
	char c;
	int a, b, n;

	cin >> n;
	
	while(n--){

		cin >> a >> c >> b;
		int x = int(c);

		if(a == b)
			cout << a*b << endl;
		else
			if(x > 96)	//minuscula
				cout << a+b << endl;
			else	//maiusculo
				cout << b-a << endl;

	}

	return 0;
}