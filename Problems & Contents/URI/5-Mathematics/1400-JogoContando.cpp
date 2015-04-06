#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


const int TRAS = 0;
const int FRENTE = 1;


bool ehMultiploOuTem7(int n){

	if(n%7 == 0)
		return true;

	while(n > 0){
		if(n%10 == 7)
			return true;
		n /= 10;
	}
	
	return false;
}


int main(){

	
	int n, m, k, p, i, q;
	int direcao;

	while(scanf("%d %d %d", &n, &m, &k) and n+m+k > 0){

		direcao = FRENTE;
		i = p = 1;
		q = 0;

		while(true){

			if(p == n)
				direcao = TRAS;
			else if(p == 1)
				direcao = FRENTE;

			if(p == m and ehMultiploOuTem7(i)){
				q++;
				if(q == k)
					break;
			}

			p = (direcao == FRENTE) ? p+1 : p-1;
			i++;
		}


		printf("%d\n", i);

	}

	return 0;
}