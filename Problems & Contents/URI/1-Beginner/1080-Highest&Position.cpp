#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

int main(){

	int n, bigger=0, biggeri=1;

	for(int i=1; i<=MAX; i++){
		cin >> n;
		if(n > bigger){
			bigger = n;
			biggeri = i;
		}
	}

	cout << bigger << endl;
	cout << biggeri << endl;

	return 0;
}