#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;




int main(){
 	
 	
	int n, m, p, t;
	string s;
	double x;

	scanf("%d", &n);
	while(n--){

		map<string, double> produtos;

		scanf("%d\n", &m);
		while(m--){
			cin >> s >> x;
			produtos[s] = x;
		}

		scanf("%d\n", &p);
		double total = 0;
		while(p--){
			cin >> s >> t;
			total += (t*produtos[s]);
		}

		printf("R$ %.2lf\n", total);

	}

 
	return 0;
}