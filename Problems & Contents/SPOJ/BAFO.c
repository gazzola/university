#include <stdio.h>

int main(){

    unsigned int a,b,r, sa, sb, count=1;

    while(1){
        scanf("%d", &r);
        if(r==0)
            break;

        sa = 0;
        sb = 0;

        while(r--){
            scanf("%d %d", &a, &b);
            sa += a;
            sb += b;
        }

        if(sa>sb)
            printf("Teste %d\nAldo\n\n", count++);
        else
            printf("Teste %d\nBeto\n\n", count++);

    }

    return 0;
}
