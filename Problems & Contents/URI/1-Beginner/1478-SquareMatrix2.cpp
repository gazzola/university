#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int printMatrix(int n){
 
    int count = 0, val;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
             
            val = abs(i-j)+1;
            printf("%3d", val);
             
            if(j < n-1)
                printf(" ");
 
        }
        printf("\n");
    }
}
 
 
int main(){
 
    int n;
    while(true){
 
        cin >> n;
 
        if(n == 0)
            break;
 
        printMatrix(n);
        printf("\n");
 
        first = true;
    }
 
 
    return 0;
}