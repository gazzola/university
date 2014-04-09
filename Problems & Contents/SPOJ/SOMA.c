#include <stdio.h>

int main(){

int n,a,som=0;
scanf("%d", &n);
while(n--){
scanf("%d", &a);
som += a;
}

printf("%d", som);


return 0;
}
