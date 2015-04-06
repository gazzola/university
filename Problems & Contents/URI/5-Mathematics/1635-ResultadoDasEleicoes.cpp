#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;



bool ehOp(string &s){
	char c = s[0];
	return (c == '>' or c == '<' or c == '=');
}

bool ehNum(string &s){
	for(int i=0; i<(int) s.size(); i++)
		if(s[i] < '0' or s[i] > '9')
			return false;
	return true;
}


int main(){
	
	int p, a, x, y;
	string s, t;
	char c;

	map<string, int> partidos;

	while(scanf("%d %d", &p, &a) != EOF){

		for(int i=0; i<p; i++){
			cin >> s;

			scanf("%d%c", &x, &c);
			x *= 10;
			if(c == '.'){
				scanf("%d\n", &y);
				x += y;
			}

			partidos[s] = x;
		}


		for(int i=1; i<=a; i++){
			
			int total = 0;
			bool res = false;

			while(true){

				cin >> s;
				if(ehOp(s)){

					cin >> x;
					x *= 10;

					switch(s[0]){
						case '>':
							if(s[1] == '=')
								res = (total >= x);
							else
								res = (total > x);
							break;
						
						case '<':
							if(s[1] == '=')
								res = (total <= x);
							else
								res = (total < x);
							break;
						
						case '=':
							res = (total == x);
							break;
					}

					break;
				}
				else if(s != "+")
					total += partidos[s];
			}

			if(res)
				printf("Guess #%d was correct.\n", i);
			else
				printf("Guess #%d was incorrect.\n", i);

		}


	}


	return 0;
}