#include <iostream>
#include <cstdio>

using namespace std;

// algoritmo de euclides
int mdc(int a, int b){
	
	int temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}

	return temp;
}


bool ehTripla(int x, int y, int z){
	
	if(x*x == y*y + z*z)
		return true;
	
	if(y*y == x*x + z*z)
		return true;
	
	if(z*z == x*x + y*y)
		return true;

	return false;
}

bool ehPrimitiva(int x, int y, int z){
	int s = mdc(x, y);
	s = mdc(s, z);
	return (s == 1);
}


int main(){

	int x, y, z;
	while(scanf("%d %d %d", &x, &y, &z) != EOF){

		if(ehTripla(x, y, z))
			if(ehPrimitiva(x, y, z))
				printf("tripla pitagorica primitiva\n");
			else
				printf("tripla pitagorica\n");
		else
			printf("tripla\n");

	}

	return 0;
}