#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, a, b;

	while(true){

		cin >> a >> b;
		if(a==0 && b==0)
			break;

		int c = a-(b-a);
		cout << c << endl;

	}

	return 0;
}