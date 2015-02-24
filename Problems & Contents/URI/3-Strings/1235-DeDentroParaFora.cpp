#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <cctype>
#include <string>

using namespace std;



int main(){
	
	

	char s[105];
	int t;
	
	scanf("%d", &t);
	getchar();

	while(t--){
		
		gets(s);
		int n = strlen(s);
		
		for (int i=n/2 - 1; i>=0; i--)
			putchar(s[i]);
		
		for (int i=n-1; i>=n/2; i--)
			putchar(s[i]);
		
		putchar('\n');
	}
	
	return 0;
}
