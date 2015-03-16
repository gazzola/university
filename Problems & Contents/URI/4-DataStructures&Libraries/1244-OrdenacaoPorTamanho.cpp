#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool orderBy(const string &x, const string &y){
	return x.size() > y.size();
}



int main(){
 	
 	

	int n;
	scanf("%d\n", &n);

	while(n--){

		char c;
		vector<string> vet;
		string s;
		while(scanf("%c", &c)){
			if(c == ' '){
				vet.push_back(s);
				s.clear();
			}
			else if(c == '\n'){
				vet.push_back(s);
				s.clear();
				break;
			}
			else{
				s.push_back(c);
			}
		}

		stable_sort(vet.begin(), vet.end(), orderBy);

		cout << vet[0];
		for(int i=1; i<(int) vet.size(); i++)
			cout << " " << vet[i];
		cout << endl;
	}

 
	return 0;
}