#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int n){
	return ((n & 1) == 0);
}


int main(){

	int a, b, c, d;
	string msg = "Valores nao aceitos";

	cin >> a >> b >> c >> d;

	if(b > c && d > a && (c+d)>(a+b) && c>0 && d>0 && isEven(a))
		msg = "Valores aceitos";

	cout << msg << endl;

	return 0;
}