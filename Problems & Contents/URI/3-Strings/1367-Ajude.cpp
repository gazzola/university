#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int ctoi(char c){
	return (int) c - 'A';
}


int main(){


	int n, t, inc[30];
	char c, julg[15];


	while(scanf("%d\n", &n) and n > 0){

		memset(inc, 0, sizeof(inc));

		int total = 0;
		int ac = 0;
		while(n--){

			scanf("%c %d %s\n", &c, &t, julg);
			int k = ctoi(c);

			if(julg[0] == 'i'){
				inc[k] += 20;
			}
			else{
				ac++;
				total += t;
				total += inc[k];
			}

		}

		printf("%d %d\n", ac, total);


	}


	return 0;
}