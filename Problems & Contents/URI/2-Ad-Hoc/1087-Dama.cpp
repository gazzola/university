#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){
	
	int x1, y1, x2, y2, result;
	while(true){

		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
			break;

		if(x1 == x2 && y1 == y2)
			result = 0;
		else if((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
			result = 1;
		else if(x1-y1 == x2-y2)
			result = 1;
		else if(abs(x2-x1) == abs(y2-y1))
			result = 1;
		else
			result = 2;

		cout << result << endl;
	}

	return 0;
}