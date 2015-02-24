#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int ctoi(char c){
	return (int) c - 'A';
}


void printCharBits(int x){
	int i = 0;
	while(x > 0){
		if((x&1) == 1)
			printf("%c", 'A'+i);

		i++;
		x >>= 1;
	}
	printf("\n");
}

int main(){

	

	char c;
	int t, x;

	scanf("%d\n", &t);
	while(t--){

		int bitmask=0, aux;
		bool ok = true;

		// cin >> comida;
		while(scanf("%c", &c) and c != '\n')
			bitmask |= (1 << ctoi(c));

		aux = bitmask;

		while(scanf("%c", &c) and c != '\n'){
			x = (1 << ctoi(c));
			if((x & aux) != x)
				ok = false;
			bitmask &= ~(x);
		}

		while(scanf("%c", &c) != EOF and c != '\n'){
			x = (1 << ctoi(c));
			if((x & aux) != x)
				ok = false;
			bitmask &= ~(x);
		}

		if(ok)
			printCharBits(bitmask);
		else
			printf("CHEATER\n");
	}


	return 0;
}