#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int n, x, lowern, lowerp, c=0;
	bool first = true;

	cin >> n;

	while(n--){

		cin >> x;

		if(first){
			lowern = x;
			lowerp = c;
			first =false;
		}
		else{
			if(x < lowern){
				lowern = x;
				lowerp = c;
			}
		}

		c++;
	}

	cout << "Menor valor: " << lowern << endl;
	cout << "Posicao: " << lowerp << endl;

	return 0;
}