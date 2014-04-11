#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;


int main(){
	
	string name, lastname="";
	int note, count=0, result=0;

	while(true){

		getline(cin, name);

		if(name == lastname)
			break;
	
		cin >> note;
		result += note;
		count++;

		getline(cin, lastname);
		lastname = name;
	}

	cout << fixed << setprecision(1) << double(result)/count << endl;

	return 0;
}