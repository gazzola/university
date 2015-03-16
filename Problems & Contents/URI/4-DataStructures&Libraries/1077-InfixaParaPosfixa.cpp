#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> ii;


int pre(char c){
	if(c == '^')
		return 3;
	else if(c == '/' or c == '*')
		return 2;
	else if(c == '+' or c == '-')
		return 1;
	return 0;
}


bool daParaTirar(char a, char b){

	if(pre(b) == 0)
		return false;

	if(a == '^')
		return (pre(a) < pre(b));

	return (pre(a) <= pre(b));
}


string eval(stack<char> &pilha, char c){
	string s;
	while(!pilha.empty() and daParaTirar(c, pilha.top())){
		s.push_back(pilha.top());
		pilha.pop();
	}
	pilha.push(c);
	return s;
}


string getToken(stack<char> &pilha){
	string s;
	while(pilha.top() != '('){
		s.push_back(pilha.top());
		pilha.pop();
	}
	pilha.pop();
	return s;
}


deque<ii> acharParenteses(string s){

	deque<ii> parenteses;
 	stack<int> aux;
	
	for(int i=0; i<(int) s.size(); i++){
		if(s[i] == '(')
			aux.push(i);
		else if(s[i] == ')'){
			parenteses.push_back(ii(aux.top(), i));
			aux.pop();
		}
	}

	return parenteses;
}



int main(){
	
	
	int t;

	scanf("%d", &t);
	while(t--){


		string s;
		cin >> s;

		s = "("+s+")";

		// deque<ii> parenteses = acharParenteses(s);
		stack<char> pilha;

		for(int i=0; i<(int) s.size(); i++){
			if(s[i] == '(')
				pilha.push(s[i]);
			else if(s[i] == ')')
				cout << getToken(pilha);
			else if(pre(s[i]) > 0)
				cout << eval(pilha, s[i]);
			else
				cout << s[i];
		}

		cout << endl;

	}

	return 0;
}