#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
bool reverseOrder(const int &i, const int &j){
	return i > j;
}
 
 
int main(){
 
	int n, x;
	scanf("%d", &n);

	vector<int> pares;
	vector<int> impares;

	while(n--){
		scanf("%d", &x);
		if(x % 2 == 0)
			pares.push_back(x);
		else
			impares.push_back(x);
	}

	sort(pares.begin(), pares.end());
	sort(impares.begin(), impares.end(), reverseOrder);

	for(int i=0; i<(int) pares.size(); i++)
		printf("%d\n", pares[i]);
 
 	for(int i=0; i<(int) impares.size(); i++)
		printf("%d\n", impares[i]);
 
	return 0;
}