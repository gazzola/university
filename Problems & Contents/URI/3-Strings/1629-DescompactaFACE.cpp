#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


int ctoi(char c){
	return (int) c - '0';
}

int somaDigitos(int n){

	int t = 0;
	while(n > 0){
		t += n%10;
		n /= 10;
	}

	return t;
}


int main(){

	int t, n;
	char numero[10001];

	while(scanf("%d\n", &t) and t > 0){
		while(t--){

			scanf("%s%n\n", numero, &n);

			int x=0, y=0;

			for(int i=0; i<n; i++){
				if(i%2 == 0)
					x += ctoi(numero[i]);
				else
					y += ctoi(numero[i]);
			}

			printf("%d\n", somaDigitos(x)+somaDigitos(y));
		
		}
	}


	return 0;
}

