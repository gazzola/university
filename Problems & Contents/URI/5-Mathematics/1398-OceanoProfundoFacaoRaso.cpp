#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;



int ctoi(char c){
	return (int) c - '0';
}


// (a * b) % m = ((a % m) * (b % m)) % m
bool isMultipleBin(string bin, int m){

	int n = bin.size()-2;
	unsigned int p = 1;
	unsigned int total = 0;

	for(int i=n; i>=0; i--){
		total += ctoi(bin[i])*p;
		total = total % m;
		p *= 2;
		p = p % m;
	}

	return (total%m == 0);
}



int main(){

	const int m = 131071;
	int n;
	string bin, s;

	bin = "";
	while(cin >> s){

		bin += s;
		
		n = s.size();
		if(s[n-1] != '#')
			continue;
		
		if(isMultipleBin(bin, m))
			printf("YES\n");
		else
			printf("NO\n");

		bin.clear();
	}


	return 0;
}