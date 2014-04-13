#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int a, d, x;

	while(true){

		cin >> a >> d;
		if(a==0 && d==0)
			break;

		int menorb=999999;
		for(int i=0; i<a; i++){
			cin >> x;
			if(x < menorb)
				menorb = x;
		}
			
		int menorc1=999999, menorc2=999999;
		for(int i=0; i<d; i++){
			cin >> x;
			if(x < menorc2){
				int temp = x;
				menorc2 = x;
				if(temp < menorc1){
					menorc2 = menorc1;
					menorc1 = temp;
				}
			}
		}

		if(menorb >= menorc2)
			cout << "N" << endl;
		else if(menorb >= menorc2 && menorb >= menorc1)
			cout << "N" << endl;
		else
			cout << "Y" << endl;

	}

	return 0;
}