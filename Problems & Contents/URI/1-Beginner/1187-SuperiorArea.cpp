#include <iostream>
#include <iomanip>

using namespace std;

//M 2.5
//S 74.3

int main(){

	char op;
	int limit=0, n=144, i=0, j=0;
	double x, sum=0;
    int at = ((12+12)/2)-1;

	cin >> op;

	while(n--){
		cin >> x;

		if(j+i < at && j > i){
			sum += x;
			limit++;
		}

		j++;
	
		if(j == 12){
			i++;
			j = 0;
		}

	}

	if(op == 'S')
		cout << fixed << setprecision(1) << sum << endl;
	else
		cout << fixed << setprecision(1) << sum/limit << endl;

	return 0;
}