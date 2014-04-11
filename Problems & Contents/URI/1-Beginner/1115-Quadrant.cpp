#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	string msg;
	int x, y;

	while(true){
		cin >> x >> y;

		if(x==0 || y==0)
			break;

		if(x > 0 && y > 0)
			msg = "primeiro";
		else if(x < 0 && y > 0)
			msg = "segundo";
		else if(x < 0 && y < 0)
			msg = "terceiro";
		else
			msg = "quarto";

		cout << msg << endl;
	}


	return 0;
}