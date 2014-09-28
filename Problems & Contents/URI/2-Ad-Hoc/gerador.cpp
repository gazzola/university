#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
		
	srand(time(NULL));

	int k = 10;

	while(k--){

		int a,b,c;
		a = (rand()%100);
		b = (rand()%100);
		c = (rand()%100);
		printf("%d %d %d\n", a, b, c);
		for(int i=0; i<b; i++){
			int x = (rand()%101);
			int y = (rand()%101);
			cout << x << " " << y << endl;
		}

		for(int i=0; i<c; i++){
			int x = (rand()%101);
			cout << x << endl;
		}
	}

	return 0;
}

/*
1
3 1 3
4 20
3
4
5