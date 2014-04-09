#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159


int main(){

	int radius;
	double result;

	cin >> radius;
	result = (4.0/3) * PI * (radius*radius*radius);

	cout << "VOLUME = " << fixed << setprecision(3) << result << endl;

	return 0;
}