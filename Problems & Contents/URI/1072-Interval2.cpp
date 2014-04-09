#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n, x, sumin=0, sumout=0;
	cin >> n;

	while(n--){
		cin >> x;
		if(x >= 10 && x <= 20)
			sumin++;
		else
			sumout++;
	}
    
    cout << sumin << " in" << endl;
    cout << sumout << " out" << endl;

	return 0;
}