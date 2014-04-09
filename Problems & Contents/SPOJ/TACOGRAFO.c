#include <stdio.h>

int main(){

    int n,v,t,som=0;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &v, &t);
        som = som+(v*t);
    }

    printf("%d", som);

    return 0;
}
