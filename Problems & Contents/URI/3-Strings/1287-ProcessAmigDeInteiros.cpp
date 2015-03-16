#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

const string over = "2147483647";



bool ehMaior(string &s){
	if(s.size() > over.size())
		return true;
	else if(s.size() < over.size())
		return false;

	for(int i=0; i<(int) s.size(); i++){
		if(s[i] > over[i])
			return true;
		else if(s[i] < over[i])
			return false;
	}

	return false;
}


int main(){

	string s;
	int n;

	while(getline(cin, s)){

		n = s.size();

		string res;
		bool error = (n == 0) ? true : false;
		bool naozero = false;

		for(int i=0; i<n and !error; i++){
			if(s[i] == 'l'){
				res.push_back('1');
				naozero = true;
			}
			else if(tolower(s[i]) == 'o'){
				if(res.size() == 0 or naozero)
					res.push_back('0');
			}
			else if(s[i] >= '0' and s[i] <= '9'){
				if(s[i] != '0'){

					if(res.size() == 1 and res[0] == '0')
						res[0] = s[i];
					else
						res.push_back(s[i]);

					naozero = true;

				}
				else{
					if(res.size() == 0 or naozero)
						res.push_back(s[i]);
				}
			}
			else if(s[i] == ',' or s[i] == ' ')
				continue;
			else
				error = true;
		}


		if(!error and res.size() > 0)
			error = ehMaior(res);
		
		if(error or res.size() == 0)
			cout << "error" << endl;
		else
			cout << res << endl;

	}

	return 0;
}