#include <iostream>
#include <iomanip>
#include <cstdio>
 
using namespace std;


int mdc(int a, int b){
	int temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}
	return temp;
}

int achar(int x, int y){

	int m = mdc(x,y);
	x = x/m;
	y = y/m;

	return 2*(x+y);
}
 
int main(){
	 
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		int total = achar(x,y);
		printf("%d\n", total);
	}
 
	return 0;
}