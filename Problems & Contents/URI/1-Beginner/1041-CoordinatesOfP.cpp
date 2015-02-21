#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	
	double x, y;
	string msg;

	while(cin >> x >> y){

		msg = "Q4";
		if(x == 0 && y == 0)
			msg = "Origem";
		else if(x == 0 and y != 0)
			msg = "Eixo X";
		else if(y == 0 and x != 0)
			msg = "Eixo Y";
		else if(x > 0 && y > 0)
			msg = "Q1";
		else if(x < 0 && y > 0)
			msg = "Q2";
		else if(x < 0 && y < 0)
			msg = "Q3";
		else
			msg = "Q4";

		cout << msg << endl;
	}

	return 0;
}