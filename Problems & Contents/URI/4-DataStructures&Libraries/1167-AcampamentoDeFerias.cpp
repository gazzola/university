#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


typedef struct triple{
	
	int first, second;
	string third;

	triple(){}
	triple(int f, int s, string t){
		first = f;
		second = s;
		third = t;
	}

}triple;




void tirarPessoas(vector<triple> &grupo){

	int i = 0;
	int x = grupo[i].second;
	int n = grupo.size();

	while(n > 1){
		if(x % 2 != 0){
			// x = x % n;
			int q = 0;

			while(q != x){
				i = (i+1) % grupo.size();
				if(grupo[i].first == 1)
					q++;
			}

			// cout << grupo[i].third << " ";
			grupo[i].first = 0;
			x  = grupo[i].second;
			n--;
		}
		else{
			// x = x % n;
			int q = 0;

			while(q != x){
				i = (i == 0) ? grupo.size()-1 : i-1;
				if(grupo[i].first == 1)
					q++;

			}

			// cout << grupo[i].third << " ";
			grupo[i].first = 0;
			x  = grupo[i].second;
			n--;
		}
	}

	// cout << endl;
	for(int i=0; i<(int) grupo.size(); i++){
		if(grupo[i].first){
			cout << "Vencedor(a): " << grupo[i].third << endl;
			break;
		}
	}

}





int main(){
 	
 	
	int n, x;
	string s;

	while(scanf("%d\n", &n) and n > 0){

		vector<triple> grupo;
		while(n--){
			cin >> s >> x;
			// cout << s << endl;
			grupo.push_back(triple(1, x, s));
		}

		tirarPessoas(grupo);
	}


 
	return 0;
}