#include <cstdio>

int diff(int *a, int *b){
	if(*a > *b)
		return *a - *b;
	else
		return *b - *a;
}


int main(){
	
	int n, qt, s, x, i, sVal, sPos, sTemp, ok;

	scanf("%d", &n);
	while(n--){

		scanf("%d %d", &qt, &s);


		sVal = 200;
		ok = 0;
		for(i=1; i<=qt; i++){
			scanf("%d", &x);
			
			if(ok)
				continue;
			
			if(x == s){
				sPos = i;
				ok = 1;
			}
			else{
				sTemp = diff(&s, &x);
				if(sTemp < sVal){
					sVal = sTemp;
					sPos = i;
				}
			}
			
		}

		printf("%d\n", sPos);
	}


	return 0;
}
