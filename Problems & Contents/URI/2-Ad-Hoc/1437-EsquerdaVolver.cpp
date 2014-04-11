#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){

	int n, pos, cd, ce;
	char c;


	while(true){
		
		cin >> n;
		if(n==0)
			break;

		pos=0;
		cd = ce = 0;

		while(n--){
			cin >> c;
			if(c=='D'){
				if(pos == 3)
					pos = 0;
				else
					pos++;
			}
			else{
				if(pos == -3)
					pos = 0;
				else
					pos--;
			}
		}

		int x = abs(pos);

		if(x == 0 || x == 3)
			cout << "N" << endl;
		else if(x == 1){
			if(pos < 0)
				cout << "O" << endl;
			else
				cout << "L" << endl;
		}
		else if(x == 2)
			cout << "S" << endl;


	}

	return 0;
}