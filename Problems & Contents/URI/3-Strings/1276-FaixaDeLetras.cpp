#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;


typedef pair<char, char> cc;


int ctoi(char c){
	return (int) c - 'a';
}


char itoc(int i){
	return (char) i + 'a';
}


int main(){

	
	bool letras[30];
	char s[55], c;
	int n;

	while(scanf("%[^\n]%n", s, &n) != EOF){

		scanf("%c", &c);
		if(s[0] == c){
			printf("\n");
			continue;
		}

		memset(letras, false, sizeof(letras));

		// printf("%d:%s\n", n, s);

		for(int i=0; i<n; i++)
			if(s[i] != ' ')
				letras[ctoi(s[i])] = true;
		

		vector<cc> faixas;
		int i = 0;
		while(!letras[i])
			i++;

		faixas.push_back(cc(itoc(i), ' '));
		i++;

		for(; i<26; i++){
			if(letras[i]){
				if(letras[i-1])
					faixas.back().second = itoc(i);
				else
					faixas.push_back(cc(itoc(i), ' '));
			}
		}

		printf("%c:%c", faixas[0].first, (faixas[0].second == ' ') ? faixas[0].first : faixas[0].second);
		for(i=1; i<(int) faixas.size(); i++)
			printf(", %c:%c", faixas[i].first, (faixas[i].second == ' ') ? faixas[i].first : faixas[i].second);

	
		printf("\n");
		s[0] = '\n';

	}



	return 0;
}