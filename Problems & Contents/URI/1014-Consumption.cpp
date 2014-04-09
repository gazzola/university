#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int X;
	double Y, result;

	cin >> X >> Y;

	result = X/Y;

	cout << fixed << setprecision(3) 
		 << result << " km/l" << endl;

	return 0;
}