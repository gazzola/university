#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int t, x, sum;
	cin >> t;

	while(t--){

		cin >> x;
		sum = 0;

		for(int i=1; i<(x/2)+1; i++)
			if(x % i == 0)
				sum += i;

		if(sum == x)
			cout << x << " eh perfeito" << endl;
		else
			cout << x << " nao eh perfeito" << endl;

	}

	return 0;
}