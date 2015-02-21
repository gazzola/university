#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int ctoi(char c){
	return (int) c - '0';
}

int main(){
	
	int n, t;
	char s[1001];

	int led[11];
	led[0] = 6;
	led[1] = 2;
	led[2] = 5;
	led[3] = 5;
	led[4] = 4;
	led[5] = 5;
	led[6] = 6;
	led[7] = 3;
	led[8] = 7;
	led[9] = 6;

	scanf("%d", &n);
	while(n--){
		
		scanf("%s%n", s, &t);

		int res = 0;
		for(int i=0; i<t-1; i++)
			res += led[ctoi(s[i])];

		printf("%d leds\n", res);
	}
	
	return 0;
}
