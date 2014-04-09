#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int n){
	return ((n & 1) == 0);
}


int main(){

	int odd=0, even=0, pos=0, neg=0, t;

    for(int i=0; i<5; i++){
        cin >> t;
        if(isEven(t))
            even++;
        else
        	odd++;

        if(t>0)
        	pos++;
        else if(t<0)
        	neg++;
    }

    cout << even << " valor(es) par(es)" << endl;
    cout << odd << " valor(es) impar(es)" << endl;
    cout << pos << " valor(es) positivo(s)" << endl;
    cout << neg << " valor(es) negativo(s)" << endl;

	return 0;
}