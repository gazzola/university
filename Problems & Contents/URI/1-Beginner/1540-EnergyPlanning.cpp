#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main(){

	unsigned long int n;
	double result, a, b, c, d;

	cin >> n;

	while(n--){

		cin >> a >> b >> c >> d;
		result = (d-b)/(c-a);
		
		char msg[16];
		char *dot;
		sprintf(msg,"%.3f", result);
		
		int t = strlen(msg);
		msg[t-1] = msg[t];

		dot = strchr(msg,'.');
		if(dot)
			*dot = ',';

		printf("%s\n",msg);
	}

	return 0;
}