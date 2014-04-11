#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	char op;
	int line, limit=12, n=144, count=1;
	double x, sum=0;

	cin >> line >> op;

	int correcPos = line*limit;
	int correcOut = correcPos+limit;

	while(n--){
		cin >> x;

		if(count > correcPos && count <= correcOut)
			sum += x;

		if(count > correcOut)
			break;

		count++;
	}

	if(op == 'S')
		cout << fixed << setprecision(1) << sum << endl;
	else
		cout << fixed << setprecision(1) << sum/limit << endl;

	return 0;
}