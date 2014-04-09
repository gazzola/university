#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int deltaT(int v, int s){
	return s/(float(v)/60); //transform to minutes
}


int main(){

	int s, v=90-60; //delta v
	
	cin >> s;

	cout << deltaT(v, s) << " minutos" << endl;

	return 0;
}