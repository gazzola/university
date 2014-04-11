#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	string name;
	double salary, sales, result;

	cin >> name >> salary >> sales;
	result = salary+(0.15*sales);
	cout << "TOTAL = R$ " << fixed << setprecision(2) << result << endl;

	return 0;
}