#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 2


int main(){

	int codes[MAX], numbers[MAX];
	double values[MAX], result=0;

	for(int i=0; i<MAX; i++){
		cin >> codes[i] >> numbers[i] >> values[i];
		result += numbers[i]*values[i];
	}

	cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << result << endl;

	return 0;
}