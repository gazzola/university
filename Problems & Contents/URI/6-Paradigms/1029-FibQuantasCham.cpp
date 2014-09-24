#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int fibVal[40] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610,
					987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025,
					121393, 196418, 317811, 514229, 832040, 1346269, 2178309,
					3524578, 5702887, 9227465, 14930352, 24157817, 39088169,
					63245986};

int fibCham[40];


int fibRec(int n){
	
	if(n <= 1)
		return 0;
	
	if(fibCham[n] == -1)
		fibCham[n] = fibRec(n-1)+1 + fibRec(n-2)+1;
	
	return fibCham[n];
	
}


int main(){

	

	int n, x;
	scanf("%d", &n);

	while(n--){
		scanf("%d", &x);

		memset(fibCham, -1, sizeof(fibCham));
		int chamadas = fibRec(x);
		printf("fib(%d) = %d calls = %d\n", x, chamadas, fibVal[x]);

	}


	return 0;
}