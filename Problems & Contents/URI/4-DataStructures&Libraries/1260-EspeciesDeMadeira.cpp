#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main(){
 
	int n;

	std::ios::sync_with_stdio(false);
	string s, c;
	map<string, int>::const_iterator iter;
	

	cin >> n;
	getline(cin, s);
	getline(cin, s);


	while(n--){

		map<string, int> arvores;
		int total = 0;

		while(getline(cin, s) and s != ""){
			arvores[s]++;
			total++;
		}
	
		for(iter=arvores.begin(); iter!=arvores.end(); iter++)
			printf("%s %.4lf\n", iter->first.c_str(), (100.0*iter->second/total));
		
		if(n)
			printf("\n");
	}


 
	return 0;
}