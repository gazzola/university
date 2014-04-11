#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, m, passou, primeira, ultima, divisor;

	while(true){

		cin >> n;
		if(n == 0)
			break;

		m = 1;
		while(true){

			passou = 1;
			primeira = 1;
			ultima = 13;
			divisor = n;

			while(primeira != ultima){

				if(primeira < ultima)
					ultima--;

				divisor--;
				passou++;
				primeira = (primeira + m) % divisor;
			}

			if(passou == n){
				cout << m+1 << endl;
				break;
			}

			m++;
		}

	}

	return 0;
}