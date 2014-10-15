#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
 
 
using namespace std;
 
bool ehLigacao(char c1, char c2){
	if((c1 == 'B' and c2 == 'S') or (c1=='S' and c2=='B'))
		return true;
	else if((c1 == 'C' and c2 == 'F') or (c1=='F' and c2=='C'))
		return true;
	return false;
}
 
 
int main(){
 
	
 
	char palavra[301];
	while(scanf("%s", palavra) != EOF){
 		
 		stack<char> pilha;
		pilha.push(palavra[0]);
		int ligs = 0;
 
		for(int i=1; palavra[i]!='\0'; i++){
 
			if(!pilha.empty()){
				if(ehLigacao(palavra[i], pilha.top())){
					ligs++;
					pilha.pop();
				}
				else
					pilha.push(palavra[i]);
			}
			else
				pilha.push(palavra[i]);
 
		}
 
		printf("%d\n", ligs);
 
	}
 
 
 
	return 0;
}