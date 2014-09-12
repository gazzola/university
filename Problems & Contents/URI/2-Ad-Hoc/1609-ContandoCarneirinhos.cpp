#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>

using namespace std;



int main(){
	
	
	int t, n, x;


	scanf("%d", &t);
	while(t--){

		set<int> carneiros;
		//map<int, bool> carneiros;
		scanf("%d", &n);

		//unsigned long int total = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &x);
			
			//if(carneiros.find(x) == carneiros.end()){
			//	total++;
			//}

			//carneiros[x] = true;
			carneiros.insert(x);
		}

		//printf("%lu\n", total);
		printf("%lu\n", carneiros.size());
	}




	return 0;
}