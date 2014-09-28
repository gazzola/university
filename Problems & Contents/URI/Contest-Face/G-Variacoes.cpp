#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cctype>
 
using namespace std;
 
 
int main(){
	 
	int n;
	char palavra[20];
	
	scanf("%d", &n);
	while(n--){

		scanf("%s", palavra);
		unsigned long long int total = 1;

		for(int i=0; palavra[i]!='\0'; i++){
			if(toupper(palavra[i]) == 'A')
				total *= 3;
			else if(toupper(palavra[i]) == 'E')
				total *= 3;
			else if(toupper(palavra[i]) == 'I')
				total *= 3;
			else if(toupper(palavra[i]) == 'O')
				total *= 3;
			else if(toupper(palavra[i]) == 'S')
				total *= 3;
			else
				total *= 2;
		}

		printf("%llu\n", total);

	}
 
	return 0;
}