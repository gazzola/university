#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n, s=0, c=0;
	
	while(true){
		cin >> n;
		
		if(n < 0)
			break;

		s += n;
		c++;
	}

	cout << fixed << setprecision(2) << double(s)/c << endl;

	return 0;
}