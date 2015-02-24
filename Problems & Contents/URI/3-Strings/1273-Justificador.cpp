#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;



int main(){

	int t, n;
	char s[51][60];
	bool first = true;

	
	while(scanf("%d\n", &t) and t > 0){
		
		if(!first)
			printf("\n");

		int m = 0;
		for(int i=0; i<t; i++){
			scanf("%s%n\n", s[i], &n);
			m = max(m, n);
		}
		

		for(int i=0; i<t; i++)
			printf("%*s\n", m, s[i]);

		first = false;
	}


	return 0;
}