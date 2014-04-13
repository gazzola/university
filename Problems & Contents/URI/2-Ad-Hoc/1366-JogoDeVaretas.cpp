#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int main(){
	
	int n, a, b, count;

	while(true){
		
		cin >> n;
		if(n == 0)
			break;

		count = 0;
		while(n--){
			cin >> a >> b;
			count += b/2;
		}

		cout << count/2 << endl;

	}

	return 0;
}