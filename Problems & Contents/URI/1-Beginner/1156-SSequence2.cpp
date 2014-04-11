#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	double s=0;
	for(int i=1, j=1; i<=39; i+=2, j*=2)
		s += double(i)/j;

	cout << fixed << setprecision(2) << s << endl;

	return 0;
}