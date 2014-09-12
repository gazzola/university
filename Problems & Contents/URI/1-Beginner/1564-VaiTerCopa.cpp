#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int main(){
 
	int n;
	while(scanf("%d", &n) != EOF){
		if(n > 0)
			printf("vai ter duas!\n");
		else
			printf("vai ter copa!\n");
	}
 
 
	return 0;
}