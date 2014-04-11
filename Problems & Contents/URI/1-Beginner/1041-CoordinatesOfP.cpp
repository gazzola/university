#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	
	double x, y;
	string msg = "Q4";

	cin >> x >> y;

	if(x == 0 && y == 0)
		msg = "Origem";
	else if(x == 0 && y != 0)
		msg = "Eixo Y";
	else if(x != 0 && y == 0)
		msg = "Eixo X";
	else if(x > 0 && y > 0)
		msg = "Q1";
	else if(x < 0 && y > 0)
		msg = "Q2";
	else if(x < 0 && y < 0)
		msg = "Q3";

	cout << msg << endl;

	return 0;
}