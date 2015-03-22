#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


int main(){

	int n;
	string s;

	scanf("%d\n", &n);
	while(n--){

		cin >> s;

		sort(s.begin(), s.end());

		cout << s << endl;
		while(next_permutation(s.begin(), s.end()))
			cout << s << endl;
		
		cout << endl;

	}

	return 0;
}