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
	
	

	char s1[55], s2[55];
	int t;
	
	scanf("%d\n", &t);

	while(t--){
		
		int n1, n2;
		scanf("%s%n ", s1, &n1);
		scanf("%s%n\n", s2, &n2);

		if(n1 < n2){

			int i;
			for(i=0; i<n1; i++)
				printf("%c%c", s1[i], s2[i]);

			for(int j=i; j<n2; j++)
				printf("%c", s2[j]);

			printf("\n");
		}
		else{

			int i;
			for(i=0; i<n2; i++)
				printf("%c%c", s1[i], s2[i]);

			for(int j=i; j<n1; j++)
				printf("%c", s1[j]);

			printf("\n");
		}

		
	}
	
	return 0;
}
