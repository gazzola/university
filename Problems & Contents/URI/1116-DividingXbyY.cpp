#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	string msg;
	int n, x, y;
	double c;

	cin >> n;

	while(n--){
		cin >> x >> y;

		if(y==0){
			cout << "divisao impossivel" << endl;
		}
		else{
			c = double(x)/y;
			cout << fixed << setprecision(1) << c << endl;
		}
	}


	return 0;
}