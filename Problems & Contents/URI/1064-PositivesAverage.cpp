#include <iostream>
#include <iomanip>

using namespace std;



int main(){

    int ammount = 0;
    int t;

    for(int i=0; i<5; i++){
        cin >> t;
        if(t > 0){
            ammount++;
            sum += t;
        }
    }

    sum /= ammount;

    cout << ammount << " valores positivos" << endl;
    cout << fixed << setprecision(1) << sum << endl;

    return 0;
}