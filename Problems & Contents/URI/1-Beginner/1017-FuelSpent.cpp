#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int main(){

	int t, v;
	double result;

	cin >> t >> v;
	result = (t*v)/12.0;

	cout << fixed << setprecision(3) << result << endl;

	return 0;
}