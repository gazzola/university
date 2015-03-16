#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>

using namespace std;



int main(){
 	
 	
	char s[1001];
	int n, t;

	scanf("%d", &t);
	while(t--){

		scanf("%s%n\n", s, &n);

		stack<char> pilha;

		int qtd = 0;
		for(int i=0; i<n; i++){
			if(s[i] == '<')
				pilha.push(s[i]);
			else if(s[i] == '>'){

				if(pilha.size() > 0 and pilha.top() == '<'){
					pilha.pop();
					qtd++;
				}
			}
		}


		printf("%d\n", qtd);
	}


 
	return 0;
}