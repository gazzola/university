#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;


bool ehLetra(char c){
	return (c >= 'A' and c <= 'Z');
}



int main(){

	char c;
	string linhas[101];
	bool first = true;

	int n;
	while(scanf("%d\n", &n) and n > 0){

		if(!first)
			printf("\n");


		int m = 0;
		for(int i=0; i<n; i++){		

			string s;
			bool espaco = false;

			while(scanf("%c", &c) and c != '\n'){
				if(ehLetra(c)){
					if(espaco and s.size() > 0)
						s.push_back(' ');
					s.push_back(c);
					espaco = false;
				}
				else
					espaco = true;
			}

			linhas[i] = s;
			m = max(m, (int) linhas[i].size());
		}


		for(int i=0; i<n; i++)
			printf("%*s\n", m, linhas[i].c_str());



		first = false;
	}




	return 0;
}