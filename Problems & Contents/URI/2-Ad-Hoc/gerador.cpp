#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int k = 10;

	while(k--){

		int c = 10;
		cout << c << endl;
		for(int i=0; i<c; i++){
			int x = (rand()%6);
			int y = (rand()%10)-5;
			cout << x << " " << y << endl;
		}
	}

	return 0;
}