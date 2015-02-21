#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



int main(){
	
	int n, t;
	char s[5];
	
	scanf("%d", &n);
	while(n--){
		
		scanf("%s%n", s, &t);
		--t;

		if(t == 5)
			printf("3\n");
		else{
			if(s[0]=='o' or s[1]=='n' or s[2]=='e')
				printf("1\n");
			else
				printf("2\n");
		}
	}
	
	return 0;
}