#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
 
 
int main(){
	 
	int x;
	char s[50];
	while(scanf("%s\n", s) and s[0] != '-'){
		if(s[1] == 'x'){
			sscanf(s, "%x", &x);
			printf("%d\n", x);
		}
		else{
			sscanf(s, "%d", &x);
			printf("0x%X\n", x);
		}
	}
 
	return 0;
}