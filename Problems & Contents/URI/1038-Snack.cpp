#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	
	double result, snack[5] = {4.00, 4.50, 5.00, 2.00, 1.50};
	int code, ammount;

	cin >> code >> ammount;

	result = snack[code-1]*ammount;
    cout << fixed << setprecision(2) <<  "Total: R$ " << result << endl;

	return 0;
}