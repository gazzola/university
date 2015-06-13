#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
 
int main(){
	 
	int a, b;
	scanf("%d %d", &a, &b);
 
	int x = 2*b/a;
	if(b % (a/2) == 0)
		x--;
 
 
	printf("%d\n", x);
}