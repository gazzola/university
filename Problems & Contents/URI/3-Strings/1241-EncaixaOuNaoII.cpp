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
	
	char a[1001];
	char b[1001];
	int t, n1, n2;

	scanf("%d", &t);
	while(t--){

		scanf("\n%s%n %s%n", a, &n1, b, &n2);
		
		n2 = n2-n1-1;
		n1--;

		// printf("%d:%s %d:%s\n", n1, a, n2, b);

		if(n2 > n1)
			printf("nao encaixa\n");
		else{

			bool ok = true;
			for(int i=n2-1, j=n1-1; i>=0; i--, j--){
				if(b[i] != a[j]){
					ok = false;
					break;
				}
			}

			if(ok)
				printf("encaixa\n");
			else
				printf("nao encaixa\n");

		}



	}


	return 0;
}
