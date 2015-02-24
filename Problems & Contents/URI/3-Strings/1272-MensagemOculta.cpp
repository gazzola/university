#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;



int main(){

	int t, n;
	char s[60];

	scanf("%d\n", &t);
	while(t--){
		
		gets(s);
		n = strlen(s);
		
		if(s[0] != ' ')
			printf("%c", s[0]);
		
		for(int i=1; i<n; i++){
			if(s[i-1] == ' ' and s[i] != ' ')
				printf("%c", s[i]);
		}

	
		printf("\n");

	}


	return 0;
}