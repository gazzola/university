#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
const int INF = 999999;


string possibilidade(map<string, int> &corretas, string &s){

	map<string, int>::iterator it;

	// 1. sem erros
	if(corretas.find(s) != corretas.end())
		return "OK";



	string errada = "NO";
	int k = INF;


	char temp;
	string s1, s2, aux;
	string outra1 = s;
	string outra2 = s;

	for(int i=0; i<(int) s.size(); i++){

		s1 = s.substr(0, i);
		s2 = s.substr(i+1);
		// cout << s1 << " - " << s2 << endl;

		for(char c='a'; c<='z'; c++){

			// caso 2.1
			aux = s1+s[i]+c+s2;
			// cout << aux << endl;
			it = corretas.find(aux);
			if(it != corretas.end()){
				if(it->second < k){
					errada = it->first;
					k = it->second;
				}
			}

			if(i == (int)s.size()-1){

				// caso 2.1
				aux = c+s1+s[i]+s2;
				// cout << aux << endl;
				it = corretas.find(aux);
				if(it != corretas.end()){
					if(it->second < k){
						errada = it->first;
						k = it->second;
					}
				}


				// caso 2.1
				aux = s1+s[i]+s2+c;
				// cout << aux << endl;
				it = corretas.find(aux);
				if(it != corretas.end()){
					if(it->second < k){
						errada = it->first;
						k = it->second;
					}
				}
			}



			aux = s1+s2;
			// if(s == "willl")
				// cout << s1 << " - " << s2 << endl;

			it = corretas.find(aux);
			if(it != corretas.end()){
				if(it->second < k){
					errada = it->first;
					k = it->second;
				}
			}


			// caso 2.2
			outra1[i] = c;
			it = corretas.find(outra1);
			if(it != corretas.end()){
				if(it->second < k){
					errada = it->first;
					k = it->second;
				}
			}

			outra1 = s;
		}


		// caso 2.3
		if(i < (int) s.size()-1){
			temp = outra2[i+1];
			outra2[i+1] = outra2[i];
			outra2[i] = temp;

			it = corretas.find(outra2);
			if(it != corretas.end()){
				if(it->second < k){
					errada = it->first;
					k = it->second;
				}
			}

			outra2 = s;
		}

	}


	return errada;

}




int main(){
	
	int n, q;
	string s, res;
	map<string, int> corretas;

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		corretas[s] = i;
	}


	cin >> q;
	while(q--){

		cin >> s;
		res = possibilidade(corretas, s);
		if(res == "OK")
			cout << s << " is correct" << endl;
		else if(res == "NO")
			cout << s << " is unknown" << endl;
		else
			cout << s << " is a misspelling of " << res << endl;

	}




	
	return 0;
}