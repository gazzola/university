#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;


int gcd(int a, int b){
	int c;
	while (a != 0){
		c = a; 
		a = b%a;  
		b = c;
	}

	return b;
}

int main(){

	string s, aux;
	map<string, int> dict;
	
	int palavras = 0;
	int jogos = 0;
	int t = 0;
	char c;

	s = "";

	char nome[250];

	while(scanf("%[A-Za-z]", nome) != EOF){
		scanf("%c", &c);
		
		printf("%s\n", nome);

		// c = tolower(c);
		// if(c >= 'a' and c <= 'z'){
		// 	s.push_back(c);
		// }
		// else{
			
		// 	if((s[0] >= 'a' and s[0] <= 'z')){
		// 		if(dict.find(s) == dict.end()){
		// 			t++;
		// 			dict[s] = 1;
		// 		}
		// 	}

		// 	if(s == "bullshit"){
		// 		palavras += t;
		// 		t = 0;
		// 		jogos++;
		// 		dict.clear();
		// 	}

		// 	s.clear();
		// }
	}

	palavras -= jogos;
	int d = gcd(abs(palavras), abs(jogos));
	
	printf("%d / %d\n", palavras/d, jogos/d);

	return 0;
}