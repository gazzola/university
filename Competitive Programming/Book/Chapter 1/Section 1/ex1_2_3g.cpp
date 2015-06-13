#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void genPermutations(string s){

}



int main(){

	string s = "ABCDEFGHIJ";
	vector<string> v;
	
	while(next_permutation(s.begin(), s.end()))
		v.push_back(s);
	
	cout << v.size() << endl;
}