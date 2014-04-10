#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	char op;
	int line, limit=12, n=144, count=0;
	double x, sum=0;

	cin >> line >> op;

	int at = line;

	while(n--){
		cin >> x;

		if(count == at){
			sum += x;
			at = at+limit;
		}

		count++;
	}

	if(op == 'S')
		cout << fixed << setprecision(1) << sum << endl;
	else
		cout << fixed << setprecision(1) << sum/limit << endl;

	return 0;
}