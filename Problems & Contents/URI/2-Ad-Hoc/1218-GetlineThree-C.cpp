#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n;
	int caso = 1;
	while(cin >> n){
		
		string s;
		getline(cin, s);
		getline(cin, s);

		int tam = s.length();
		int fem = 0;
		int masc = 0;
		int total = 0;

		for(int i=0; i<tam-3; i+=5){

			int a = s.at(i) - '0';
			int b = s.at(i+1) - '0';
			char c = s.at(i+3);
			int num = a*10 + b;
			
			if(num == n){
				total++;
				if(c == 'M')
					masc++;
				else if(c == 'F')
					fem++;

			}
		}

		if(caso > 1)
			cout << endl;

		cout << "Caso " << caso << ":" << endl;
		cout << "Pares Iguais: " << total << endl;
		cout << "F: " << fem << endl;
		cout << "M: " << masc << endl;

		caso++;


	}

	return 0;
}