#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>

using namespace std;





int main(){
 
	int n;

	while(scanf("%d\n", &n) and n > 0){

			stack<char> estacao;
			deque<char> entrada;
			deque<char> saida;

			char x;
			for(int i=0; i<n; i++){
				scanf("%c ", &x);
				entrada.push_back(x);
			}

			for(int i=0; i<n; i++){
				scanf("%c ", &x);
				saida.push_back(x);
			}

			string s;
			for(int i=0; i<n; i++){
				estacao.push(entrada[i]);
				s.push_back('I');
				while(estacao.top() == saida.front()){
					saida.pop_front();
					estacao.pop();
					s.push_back('R');
					if(estacao.empty())
						break;
				}
			}

			cout << s;
			if(estacao.size() > 0)
				cout << " Impossible";
			cout << endl;
	}

 
	return 0;
}