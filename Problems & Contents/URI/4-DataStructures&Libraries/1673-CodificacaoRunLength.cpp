#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int getQtdIguais(string &s, int k){

	int qtd = 0;
	for(int i=k+1; i<(int) s.size() and qtd < 8; i++){
		if(s[i] == s[i-1])
			qtd++;
		else
			break;
	}

	return qtd;
}



int main(){
 	
 	

	string s;

	while(getline(cin, s)){

		int n = s.size();
		int qtd;
		string aux;

		for(int i=0; i<n; i++){

			qtd = getQtdIguais(s, i);
			
			if(qtd > 0){
				cout << qtd+1 << s[i];
				i += qtd;
			}
			else{
				cout << "1";
				for(; i<n; i++){
					if(s[i] != s[i+1]){
						if(s[i] == '1')
							cout << "11";
						else
							cout << s[i];
					}
					else{
						i--;
						break;
					}
				}
				cout << "1";
			}

		}

		
		cout << endl;

	}


 
	return 0;
}