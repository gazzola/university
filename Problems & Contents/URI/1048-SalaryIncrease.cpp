#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	double salary, nsalary, swin, sratio=0.0;
	cin >> salary;

	if(salary <= 400)
		sratio = 15;
	else if(salary <= 800)
		sratio = 12;
	else if(salary <= 1200)
		sratio = 10;
	else if(salary <= 2000)
		sratio = 7;
	else if(salary > 2000)
		sratio = 4;

	
	swin = salary * sratio/100;
	nsalary = salary + swin;

	cout << fixed << setprecision(2);
	cout << "Novo salario: " << nsalary << endl;
    cout << "Reajuste ganho: " << swin << endl;
    cout << "Em percentual: " << sratio << " %" << endl;

	return 0;
}