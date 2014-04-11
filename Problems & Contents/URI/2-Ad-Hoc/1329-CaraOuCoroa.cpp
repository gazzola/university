#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n, x, cm, cj;

	while(true){

		cin >> n;

		if(n==0)
			break;

		cm=cj=0;

		while(n--){

			cin >> x;
			if(x == 0)
				cm++;
			else
				cj++;
		}

		cout << "Mary won " << cm << " times and John won " << cj << " times" << endl;

	}

	return 0;
}