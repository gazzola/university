#include <iostream>
#include <iomanip>
 
using namespace std;
 
 
int main(){
     
    int h1, m1, h2, m2;
 
    while(true){
 
        cin >> h1 >> m1 >> h2 >> m2;
 
        if(h1==0 && m1==0 && h2==0 && m2==0)
            break;
 
        int t1 = h1*60 + m1;
        int t2 = h2*60 + m2;
        int tf = (t2-t1);
 
        if(tf < 0){
            tf = (24*60) - t1 + t2;
        }
 
        cout << tf << endl;
 
    }
 
    return 0;
}