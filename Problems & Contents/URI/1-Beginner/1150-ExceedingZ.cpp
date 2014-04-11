#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int x, z, count=1, sum=0;

	cin >> x;

	while(true){
		cin >> z;
		if(z > x)
			break;
	}

	for(int i=x; i<z; i++){
		sum += i;
		if(sum > z)
			break;
		count++;
	}

	cout << count << endl;

	return 0;
}