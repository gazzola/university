#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


bool ehPalavra(string &s){

	int n = s.size();

	if(n == 1 and s[0] == '.')
		return false;

	int i = 0;
	while(i < n){
		if((s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z'))
			i++;
		else
			break;
	}

	if(i == n-1 and s[n-1] == '.')
		return true;

	return (i == n);
}



int main(){


	char c;
	string s;

	int soma = 0;
	int t = 0;

	while(scanf("%c", &c) != EOF){

		if(c == '\n'){
			
			if(ehPalavra(s) and s.size() > 0){
				if(s.back() == '.')
					soma = soma + s.size() - 1;
				else
					soma += s.size(); 
				t++;
			}

			int res = 0;
			if(t > 0)
				res = soma/t;

			if(res <= 3)
				printf("250\n");
			else if(res <= 5)
				printf("500\n");
			else
				printf("1000\n");

			soma = 0;
			t = 0;
			
			s.clear();
		}
		else if(c == ' '){
			if(ehPalavra(s) and s.size() > 0){
				if(s.back() == '.')
					soma = soma + s.size() - 1;
				else
					soma += s.size(); 
				t++;
			}

			s.clear();
		}
		else{
			s.push_back(c);
		}
	}


	return 0;
}