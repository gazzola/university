#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <cctype>
#include <string>

using namespace std;



int main(){
	
	


	string s;
	
	string i_abre = "<i>";
	string i_fecha = "</i>";
	string b_abre = "<b>";
	string b_fecha = "</b>";


	while(getline(cin, s)){
		
		int n = s.size();

		bool abriu_i = true;
		bool abriu_b = true;

		for(int i=0; i<n; i++){

			if(s[i] == '_'){
				if(abriu_i)
					cout << i_abre;
				else
					cout << i_fecha;
				abriu_i = !abriu_i;
			}
			else if(s[i] == '*'){
				if(abriu_b)
					cout << b_abre;
				else
					cout << b_fecha;
				abriu_b = !abriu_b;
			}
			else
				cout << s[i];
		}

		cout << endl;
		
	}
	
	return 0;
}
