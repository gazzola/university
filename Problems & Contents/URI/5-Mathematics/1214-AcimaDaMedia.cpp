#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
 
 
int main(){
 
    int t, n, x;
 
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
             
        scanf("%d", &n);
         
        vector<int> vet;
        int soma = 0;
 
        while(n--){
            scanf("%d", &x);
            vet.push_back(x);
            soma += x;
        }
 
        double media = soma/(double) vet.size();
        int c = 0;
        for(int i=0; i<(int) vet.size(); i++)
            if(vet[i] > media)
                c++;
 
        printf("%.3lf%%\n", 100 * c/(double) vet.size());
 
    }
 
 
    return 0;
}