#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, a, b, x, y;

	while(true){

		cin >> n;
		if(n==0)
			break;

		cin >> a >> b;

		while(n--){
			cin >> x >> y;

			if(a == x || b == y)
				cout << "divisa" << endl;
			else if(x > a && y > b)
				cout << "NE" << endl;
			else if(x < a && y > b)
				cout << "NO" << endl;
			else if(x < a && y < b)
				cout << "SO" << endl;
			else
				cout << "SE" << endl;
		}

	}

	return 0;
}