#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>

using namespace std;



int main(){
 	
 	
	char s[1001];
	int n;

	while(scanf("%s%n\n", s, &n) != EOF){

		stack<char> pilha;

		bool error = false;
		for(int i=0; i<n; i++){
			if(s[i] == '(')
				pilha.push(s[i]);
			else if(s[i] == ')'){

				if(pilha.size() > 0 and pilha.top() == '('){
					pilha.pop();
				}
				else{
					error = true;
					break;
				}
			}
		}


		if(pilha.size() == 0 and !error)
			printf("correct\n");
		else
			printf("incorrect\n");
	}


 
	return 0;
}