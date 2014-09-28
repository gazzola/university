#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


void trocaEstado(char *lampadas, int i){
	lampadas[i] = (lampadas[i] == 'o') ? 'x' : 'o'; 
}


int main(){
	

	int n, q;

	while(true){

		scanf("%d %d", &n, &q);
		if(n==0 and q ==0)
			break;


		char lampadasOld[105];
		scanf("%s", lampadasOld);


		int k, m;
		while(q--){
			scanf("%d %d", &k, &m);
			char lampadas[105];
			strcpy(lampadas, lampadasOld);

			int pos = 0;
			m = m%(n*2);

			while(m--){
				trocaEstado(lampadas, pos);
				pos = (pos+k)%n;
			}

			printf("%s\n", lampadas);
		}

	}

	
	return 0;
}