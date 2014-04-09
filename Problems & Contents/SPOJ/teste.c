#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

int iNums = 52981;
int iNumsSize = 5;
int i;
for (i=iNumsSize-1; i>=0; i--) {
    int y = pow(10, i);
    int z = iNums/y;
    int x2 = iNums / (y * 10);
    printf("%d-",z - x2*10 );
}


return 0;
}
