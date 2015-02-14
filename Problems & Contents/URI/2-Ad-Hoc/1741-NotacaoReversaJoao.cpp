#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <string>


using namespace std;


typedef long long signed int lls;

bool ehOp(char c){
	if(c == '+' or c == '-' or c == '*' or c == '/')
		return true;
	return false;
}


int myatoi(char c){
	return (int) c - '0';
}


void printConta(deque<string> &d){
	int n = d.size();
	for(int i=0; i<n; i++)
		cout << " " << d[i];
	cout << endl;
}




int main(){
	
	char sentenca[2000001];
	bool mal, zero;
	lls x, y;
	int n;

	while(scanf("%[^\n]%n\n", sentenca, &n) != EOF){

		deque<lls> conta;
		mal = zero = false;

		for(int i=n-1; i>=0; i-=2){

			if(!isdigit(sentenca[i])){

				if(conta.size() < 2){
					mal = true;
					break;
				}

				x = conta.back();
				conta.pop_back();

				y = conta.back();
				conta.pop_back();


				if(sentenca[i] == '+')
					conta.push_back(y+x);
				else if(sentenca[i] == '-')
					conta.push_back(y-x);
				else if(sentenca[i] == '*')
					conta.push_back(y*x);
				else if(sentenca[i] == '/'){
					if(x == 0){
						zero = true;
						x = 1;
					}
					conta.push_back(y/x);
				}

			}
			else{
				conta.push_back(myatoi(sentenca[i]));
			}
		}

		if(conta.size() != 1)
			mal = true;

		if(zero and !mal)
			cout << "Division by zero." << endl;
		else if(mal)
			cout << "Invalid expression." << endl;
		else
			cout << "The answer is " << conta.back() << "." << endl;

	}
	
	return 0;
}