#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int n){
	return ((n & 1) == 0);
}

int main(){

	int ammount=0, t;

    for(int i=0; i<5; i++){
        cin >> t;
        if(isEven(t))
            ammount++;
    }

    cout << ammount << " valores pares" << endl;

	return 0;
}