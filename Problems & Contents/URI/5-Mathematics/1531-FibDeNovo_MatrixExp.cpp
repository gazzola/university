/*
* Mais informacoes sobre fibonacci em O(logn):
* http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
* http://nayuki.eigenstate.org/page/fast-fibonacci-algorithms
*
* Mais informacoes sobre periodo de pisanno:
* http://en.wikipedia.org/wiki/Pisano_period
*/

#include <cstdio>
#include <cstring>

using namespace std;
typedef long long unsigned int llu;



int MOD;

void multiply(llu F[2][2], llu M[2][2]){

	llu x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
	llu y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
	llu z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
	llu w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = x % MOD;
	F[0][1] = y % MOD;
	F[1][0] = z % MOD;
	F[1][1] = w % MOD;
}


void power(llu F[2][2], int n){
  
  if(n == 0 || n == 1)
      return;

  llu M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if((n&1) == 1)
     multiply(F, M);
}


int fib(int n){

	if(n == 0)
		return 0;

	llu F[2][2] = {{1,1},{1,0}};
	power(F, n-1);
	return F[0][0];
}


int pisano(int m){

	if(m <= 1)
		return 1;
	
	int a, b, temp, i, last;
	a = b = 1;
	i = last = 0;

	while(true){
		temp = a;	
		a = b;
		b = (temp+b)%m;

		if(b==last && last==1)
			break;

		last = b;
		i++;
	}

	return i+1;
}

int main(){

	int n, m;
	llu res1, res2;

	while(scanf("%d %d",&n,&m) != EOF){

		MOD = pisano(m);
		res1 = fib(n);

		MOD = m;
		res2 = fib(res1);

		printf("%lld\n", res2);
	}

	return 0;
}