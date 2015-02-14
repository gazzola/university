#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool ehVogal(char c){
	return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
}

bool caso2(string &s, int k){
	return (!ehVogal(s[k-2]) and s[k-1] == 'y');
}

bool caso3(string &s, int k){
	return (s[k-1] == 'o' or s[k-1] == 's' or s[k-1] == 'x' or (s[k-1] == 'h' and s[k-2] == 'c')  or (s[k-1] == 'h' and s[k-2] == 's'));
}


int main(){
	
	
	int l, n;
	string s, x;

	while(cin >> l >> n){
	
		map<string, string> irregular;

		while(l--){
			cin >> s >> x;
			irregular[s] = x; 
		}

		while(n--){

			cin >> s;
			int k = s.size();

			if(irregular.count(s) > 0){
				cout << irregular[s] << endl;
			}
			else if(caso2(s, k)){
				s[k-1] = 'i';
				s += "es";
				cout << s << endl;
			}
			else if(caso3(s, k)){
				cout << s << "es" << endl;
			}
			else{
				cout << s << "s" << endl;
			}

		}

	}


	
	return 0;
}