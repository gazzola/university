#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
		
	srand(time(NULL));

	int n = 10;

	while(n--){
		
		int n = (rand()%10)+1;
		int m = (rand()%10)+1;
		int k = (rand()%n);	
		printf("%d %d %d\n", n, m, k);

		for(int i=0; i<m; i++){
			int x1 = (rand()%n)+1;
			int x2 = (rand()%n)+1;

			printf("%d %d\n", x1, x2);
		}
	}
	
	return 0;	
}