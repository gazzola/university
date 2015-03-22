#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int m;

bool orderBy(const int &x, const int &y){

	int xm = x % ::m;
	int ym = y % ::m;

	if(xm < ym)
		return true;
	else if(xm > ym)
		return false;

	if(x % 2 == 0 and y % 2 != 0)
		return false;
	else if(x % 2 != 0 and y % 2 == 0)
		return true;
	else if(x % 2 != 0 and y % 2 != 0)
		return (x > y);
	
	return (x < y);

}




int main(){

	int n, x;
	while(scanf("%d %d", &n, &m) and n > 0){

		vector<int> vet;
		while(n--){
			scanf("%d", &x);
			vet.push_back(x);
		}


		sort(vet.begin(), vet.end(), orderBy);

		printf("%d %d\n", (int) vet.size(), m);
		for(int i=0; i<(int) vet.size(); i++)
			printf("%d\n", vet[i]);
	}

	printf("0 0\n");

	return 0;
}