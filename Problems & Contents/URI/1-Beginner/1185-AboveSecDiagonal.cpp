#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	char op;
	int limit=0, n=144, i=0, j=0;
	double x, sum=0;
    int at = ((12+12)/2)-1;

	cin >> op;

	while(n--){
		cin >> x;

		if(j+i > at){
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