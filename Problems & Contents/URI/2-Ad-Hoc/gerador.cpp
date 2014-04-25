#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int n = 10;

	while(n--){
		
		int x = (rand()%100000)+1;
		cout << x << endl;
		
	}


	return 0;	
}