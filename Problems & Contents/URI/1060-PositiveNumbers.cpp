#include <iostream>

using namespace std;

int main(){

    int ammount = 0;
    double t;
    for(int i=0; i<6; i++){
        cin >> t;
        if(t > 0)
            ammount++;
    }

    cout << ammount << " valores positivos" << endl;

	return 0;
}