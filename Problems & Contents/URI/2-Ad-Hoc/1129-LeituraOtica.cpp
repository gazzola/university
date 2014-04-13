#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n, x;

	while(true){
		cin >> n;
		if(n == 0)
			break;

		while(n--){

			int preto = 0, pos;
			for(int i=0; i<5; i++){
				cin >> x;
				if(x <= 127){
					preto++;
					pos = i;
				}
			}

			if(preto == 1){
				char c = pos+65;
				cout << c << endl;
			}
			else
				cout << "*" << endl;

		}
		
	}

	return 0;
}