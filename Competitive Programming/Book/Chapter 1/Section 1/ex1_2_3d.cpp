#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;


int main(){

	set<int> s;
	set<int>::iterator it;

	int x;

	while(scanf("%d", &x) != EOF)
		s.insert(x);

	for(it=s.begin(); it!=s.end(); ++it)
		printf("%d ", *it);
}