#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, a, b, na, nb;

	while(true){

		cin >> n;
		if(n == 0)
			break;

		na = nb = 0;

		while(n--){

			cin >> a >> b;
			if(a > b)
				na++;
			else if(b > a)
				nb++;
		}

		cout << na << " " << nb << endl;
	}

	return 0;
}