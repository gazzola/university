#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int number, hours;
	double salary;

	cin >> number >> hours >> salary;

	salary *= hours;

	cout << "NUMBER = " << number << endl;
	cout << "SALARY = U$ " << fixed << setprecision(2) << salary << endl;


	return 0;
}