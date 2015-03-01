#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> si;


bool orderBy(const si &i, const si &j){
	if(i.second < j.second)
		return true;
	else if(i.second > j.second)
		return false;

	return i.first > j.first;
}

int main(){
	
	int n;
	char c, last;
	while(scanf("%d\n", &n) and n > 0){

		map<string, int> dict;
		map<string, int>::iterator it;
		vector<si> vet;

		bool first = true;
		int total = 0;

		while(n--){
			
			if(first)
				scanf("%c", &last);
			first = false;

			while(scanf("%c", &c) and c != '\n'){

				string s;
				s.push_back(last);
				s.push_back(c);
				total++;

				dict[s] += 1;
				last = c;
			}
		}


		for(it=dict.begin(); it!=dict.end(); ++it)
			vet.push_back(si(it->first, it->second));

		sort(vet.begin(), vet.end(), orderBy);
		int t = vet.size();

		for(int i=t-1; i>t-6; i--)
			printf("%s %d %.6lf\n", vet[i].first.c_str(), vet[i].second, (double) vet[i].second/total);

		printf("\n");
	}


	return 0;
}