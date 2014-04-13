#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int t, n;
	while(true){

		cin >> t >> n;
		if(t == 0)
			break;

		int sum = 0, x;
		string s;
		for(int i=0; i<t; i++){
			cin >> s >> x;
			sum += x;
		}


		cout << (3*n)-sum << endl;

	}

	return 0;
}