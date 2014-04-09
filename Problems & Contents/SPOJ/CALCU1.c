#include <stdio.h>


int main(){

    int n,d;
    double result=1;
    const double max = 1073741824;
    char op;
    scanf("%d", &n);
    while(n--){
        scanf("%d %c", &d, &op);
        if(op=='*'){
            result = result*d;
        }
        else{
            result = result/d;
        }
    }

    if(result > max)
        result = max;
    printf("%.0lf", result);

    return 0;
}
