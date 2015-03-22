#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


typedef pair<int, int> ii;


bool orderBy(const ii &x, const ii &y){
	if(x.second < y.second)
		return true;
	else if(x.second > y.second)
		return false;

	return (x.first > y.first);
}



int main(){
 	
 	char s[1001];
 	int freq[100];
 	bool first = true;


 	while(scanf("%s", s) != EOF){

 		memset(freq, 0, sizeof(freq));
 		int mn = 9999;
 		int mx = 0;

 		for(int i=0; s[i]!='\0'; i++){
 			int p = (int) s[i] - 32;
 			freq[p]++;
 			mn = min(mn, p);
 			mx = max(mx, p);
 		}

 		vector<ii> vet;
 		for(int i=mn; i<=mx; i++)
 			if(freq[i] > 0)
 				vet.push_back(ii(i, freq[i]));
 		
 		sort(vet.begin(), vet.end(), orderBy);


 		if(!first)
 			printf("\n");

 		for(int i=0; i<(int) vet.size(); i++)
 			printf("%d %d\n", vet[i].first+32, vet[i].second);

 		first = false;
 	}
 
	return 0;
}