#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){ //funcao fatorial
    if(n > 1){  // se n for maior que 1 ele calcula ele mesmo vezes a funcao dele menos um
        return n*fatorial(n-1);
    }
	else{   // senao retorna 1
        return 1;
    }
}

int main(){
    int n, result;
    scanf("%d", &n);
    result = fatorial(n);
    printf("%d\n",result);

return 0;
}
