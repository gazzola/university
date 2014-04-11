#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}


int main(){

	int n, t;
	cin >> n;
	
	while(n--){

		cin >> t;

		if(t == 0)
			cout << "NULL" << endl;
		else{

			if(isOdd(t)){
				if(t > 0)
					cout << "ODD POSITIVE" << endl;
				else
					cout << "ODD NEGATIVE" << endl;
			}
			else{
				if(t > 0)
					cout << "EVEN POSITIVE" << endl;
				else
					cout << "EVEN NEGATIVE" << endl;
			}
		}

	}

	return 0;
}