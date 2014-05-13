#include <iostream>
#include <iomanip>
#include <cstdio>
 
using namespace std;
 
 
int main(){
	 
	unsigned int a, b, result;
	while(scanf("%u %u", &a, &b) != EOF)
		printf("%u\n", a^b);
 
	return 0;
}