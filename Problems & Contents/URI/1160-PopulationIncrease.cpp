#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int t, pa, pb, dp, c;
	double g1, g2, dg;
	bool hundred;

	cin >> t;
	while(t--){

		cin >> pa >> pb >> g1 >> g2;
		hundred = false;
		c = 0;

		while(pa <= pb){

			pa += (pa*g1)/100;
			pb += (pb*g2)/100;

			c++;
			if(c > 100){
				hundred = true;
				break;
			}
		}

		if(hundred)
			cout << "Mais de 1 seculo." << endl;
		else
			cout << c << " anos." << endl;
	}

	return 0;
}