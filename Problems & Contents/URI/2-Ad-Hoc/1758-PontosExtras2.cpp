#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
 
bool compare(const double p, const double s){
return p<s;
}
int main()
{
    int t, p, n;
    double mat[50][5];
    memset(mat,0,sizeof(mat));
    scanf("%d",&t);
    for(int k=0; k<t; k++)
    {
        scanf("%d%d",&p,&n);
        for(int i=0; i<n; i++)
        {
            double total=0;
            double k = 0;
            for(int j=0; j<p; j++)
            {
                scanf("%lf",&mat[i][j]);
                if(mat[i][j] < 7)
                	k = max(k, mat[i][j]);
                total=total+mat[i][j];
            }
            double media=total/p;
            sort(mat[i],mat[i]+p,compare);
            if(media>=7){
                media=mat[i][p-1];
            }
            if((media>=4)&& (media<7)){
                 if(media<k){
                    media=k;
                }
            }
        printf("%.2lf\n",media);
        }

}
}