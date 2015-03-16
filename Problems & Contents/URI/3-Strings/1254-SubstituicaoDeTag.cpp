#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;



int main(){

	
	string ori, rep, txt;

	while(getline(cin, ori)){

		getline(cin, rep);
		getline(cin, txt);


		int j=0;
		string s;
		bool ehTag = false;

		for(int i=0; i<(int) txt.size(); i++){

			s.push_back(txt[i]);
			if(txt[i] == '<')
				ehTag = true;


			if(tolower(txt[i]) == tolower(ori[j])){
				j++;
			}
			else{
				if(j == (int) ori.size() and ehTag and txt[i] != '<'){
					cout << rep;
					j = 0;
					if(tolower(txt[i]) == tolower(ori[j]))
						j++;
					else
						cout << txt[i];
				}
				else{
					cout << s;
					j = 0;
				}

				s.clear();
			}

			if(txt[i] == '>')
				ehTag = false;

		}


		cout << endl;

	}




	return 0;
}