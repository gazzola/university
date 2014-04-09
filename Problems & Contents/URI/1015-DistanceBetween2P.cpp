#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double distance(int *x, int *y){
	return sqrt(pow((x[1]-x[0]), 2) + pow((y[1]-y[0]), 2));
}


int main(){

	int x[2], y[2];

	for(int i=0; i<2; i++)
		cin >> x[i] >> y[i];

	cout << fixed << setprecision(4) << distance(x, y) << endl;

	return 0;
}