#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


int ctoi(char c){
	return (int) c - '0';
}


int main(){

	int t, n;
	char numero[10001];

	while(scanf("%d\n", &t) and t > 0){
		while(t--){

			scanf("%s%n\n", numero, &n);

			int x=0, y=0;
			int j=0, k=0;

			for(int i=0; i<n; i++){
				if(i%2 == 0){
					if(ctoi(numero[i]) > 0)
						j++;
					x += ctoi(numero[i]);
				}
				else{
					if(ctoi(numero[i]) > 0)
						k++;
					y += ctoi(numero[i]);
				}
			}


			int mx = 9 * (j/2);
			int my = 9 * (k/2);

			if(mx > 0)
				x = x%mx;

			if(my > 0)
				y = y%my;


			if(x == 0)
				x = mx;

			if(y == 0)
				y = my;

			printf("%d\n", x+y);

		}
	}


	return 0;
}

