#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;



int main(){

	int n;
	string s;
	
	cin >> n;
	char c = getchar();
	while(n--){

		getline(cin, s);

		int tam = s.length();
		for(int i=0; i<tam; i++){
			int pos = s[i];
			if(pos >= 65 && pos <= 90 || pos >= 97 && pos <= 122) //A-Z/a-z
				s[i] = pos+3;
		}

		reverse(s.begin(), s.end());

		for(int i=tam/2; i<tam; i++)
			s[i] = int(s[i])-1;


		cout << s << endl;
	}


	return 0;
}