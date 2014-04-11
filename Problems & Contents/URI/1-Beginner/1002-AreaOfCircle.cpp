#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159


int main(){
	
	double R, A;

	cin >> R;
	A = PI*(R*R);
	cout << fixed << setprecision(4) << "A=" << A << endl;

	return 0;
}