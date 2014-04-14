#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;
 
 
int main(){
     
    int n;
 
    while(true){
         
        cin >> n;
        if(n == 0)
            break;
         
        double *vet = new double[n];
        double total=0, media, cent, real;
        int pagar=0, receber=0;
 
        for(int i=0; i<n; i++){
            cin >> real;
 
            cent = int(real-floor(real)); //get cents
            real = (real*100) + cent; //transform real to cents
 
            vet[i] = real;
            total += real;
        }
 
        media = total/double(n);
 
        for(int i=0; i<n; i++){
            if(vet[i] > media)
                pagar += vet[i] - media;
            else
                receber += media - vet[i];
        }
 

        if(pagar > receber)
            cout << fixed << setprecision(2) << "$" << double(pagar)/100.0 << endl;
        else
            cout << fixed << setprecision(2) << "$" << double(receber)/100.0 << endl;
 
 
         delete[] vet;
    }
 
    return 0;
}