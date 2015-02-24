#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;



int main(){

	char texto[10000];
	int n;

	while(scanf("%[^\n]%n\n", texto, &n) != EOF){

		int t = 0;
		int l = 1;
		char c = tolower(texto[0]);
		
		for(int i=0; i<n; i++){
			if(texto[i] == ' ' and i < n-1){
				if(tolower(texto[i+1]) == c){
					l++;
					if(l == 2)
						t++;
				}
				else{
					c = tolower(texto[i+1]);
					l = 1;
				}

				i++;
			}
		}

		printf("%d\n", t);

	}
	


	return 0;
}