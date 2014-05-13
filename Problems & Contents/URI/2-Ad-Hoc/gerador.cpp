#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int c = 50;
	cout << c << endl;
	for(int i=0; i<c; i++){
		int n = 500;
		cout << n << endl;
		for(int j=0; j<n; j++){
			int x = (rand()%10000);
			int y = (rand()%10000);
			cout << x << " " << y << endl;
		}

	}


	return 0;
}