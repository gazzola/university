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
	

	while(getline(cin, s)  and s != ""){
		
		// cout << s << endl;
		int tam = s.size();
		
		bool maiuscula = true;
		
		for(int i=0; i<tam; i++){
			s[i] = (maiuscula) ? toupper(s[i]) : tolower(s[i]);
			if(s[i] != ' ')
				maiuscula = !maiuscula;
		}

		cout << s << endl;

	}
	
	return 0;
}
