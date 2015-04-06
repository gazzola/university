#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;



int ctoi(char c){
	if(c <= '9')
		return (int) c - '0';

	if(c <= 'Z')
		return 10 + (int) c - 'A';

	return 10 + (int) c - 'a'; 
}


string binToDec(string bin){
	int n = bin.size()-1;
	int base = 2;
	
	unsigned int total = 0;
	unsigned int p = 1;

	for(int i=n; i>=0; i--){
		total += ctoi(bin[i])*p;
		p *= base;
	}

	return to_string(total);
}

string hexToDec(string hex){
	int n = hex.size()-1;
	int base = 16;
	unsigned int total = 0;
	unsigned int p = 1;

	for(int i=n; i>=0; i--){
		total += ctoi(hex[i])*p;
		p *= base;
	}

	return to_string(total);
}

string decToBin(string dec){
	unsigned int n = stol(dec);
	int base = 2;
	string s = "";
	while(n > 0){
		s = ((n%base == 0) ? "0" : "1")+s;
		n /= base;
	}
	return s;
}

string hexToBin(string hex){
	return decToBin(hexToDec(hex));
}


string getLetter(int x){
	if(x <= 9)
		return to_string(x);
	char c = x-10 + 'a';
	string s;
	s.push_back(c);
	return s;
}

string decToHex(string dec){
	unsigned int n = stol(dec);
	int base = 16;
	string s = "";

	while(n > 0){
		s = getLetter(n%base)+s;
		n /= base;
	}
	return s;
}

string binToHex(string bin){
	return decToHex(binToDec(bin));
}



int main(){

	string num, s;
	int t;
	scanf("%d\n", &t);
	
	for(int i=1; i<=t; i++){

		cin >> num >> s;

		cout << "Case " << i << ":" << endl;
		if(s[0] == 'b'){
			cout << binToDec(num) << " dec" << endl;
			cout << binToHex(num) << " hex" << endl;
		}
		else if(s[0] == 'd'){
			cout << decToHex(num) << " hex" << endl;
			cout << decToBin(num) << " bin" << endl;
		}
		else{
			cout << hexToDec(num) << " dec" << endl;
			cout << hexToBin(num) << " bin" << endl;
		}

		cout << endl;
	}


	return 0;
}