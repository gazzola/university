#include <iostream>

using namespace std;


int main(){

	long double n;
	string msg = "Fora de intervalo";
	cin >> n;

    if (n >= 0 && n <= 25)
        msg = "Intervalo [0,25]";
    else if (n > 25 && n <= 50)
        msg = "Intervalo (25,50]";
    else if (n > 50 && n <= 75)
        msg = "Intervalo (50,75]";
    else if (n > 75 && n <= 100)
        msg = "Intervalo (75,100]";

    cout << msg << endl;

	return 0;
}