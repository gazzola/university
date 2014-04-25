#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){
	
	
	int n, m, x;
	int vet[10];
	bool ok;

	while(scanf("%d %d ", &n, &m) != EOF){
		
		int count = 0;

		for(int i=n; i<=m; i++){
			
			x = i;
			ok = true;
			memset(vet, 0, sizeof(vet));
			
			while(x != 0){
				int pos = x%10;
				if(vet[pos] == 0)
					vet[pos] = 1;
				else{
					ok = false;
					break;
				}

				x /= 10;
			}

			if(ok)
				count++;
		}

		printf("%d\n", count);
	}

	return 0;
}