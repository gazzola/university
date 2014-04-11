#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n;
	double m, n1, n2, n3;

	cin >> n;
	
	while(n--){
		cin >> n1 >> n2 >> n3;
		m = (2*n1 + 3*n2 + 5*n3)/10;
		cout << fixed << setprecision(1) << m << endl;
	}
	

	return 0;
}