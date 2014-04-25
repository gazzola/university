#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


string bin(unsigned int n){
	unsigned int i;
	string s = "";
	for (i=1<<31; i>0; i=i/2)
		s += (n & i) ? "1" : "0";

	return s;
}


unsigned long int quadral(unsigned long int n){
	unsigned long int resto, i=1, quadral=0;
	while(n!=0){
		resto = n%4;
		n /= 4;
		quadral += resto*i;
		i *= 10;
	}
	return quadral;
}


string alien(string quadral){
	string s = "";
	for(int i=0, tam=quadral.length(); i<tam; i++){
		if(quadral[i] == '0')
			s += "A";
		else if(quadral[i] == '1')
			s += "B";
		else if(quadral[i] == '2')
			s += "C";
		else if(quadral[i] == '3')
			s += "D";
	}

	return s;
}



int main(){
	

	unsigned long int n;

	while(true){
		cin >> n;
		if(n==0)
			break;

		stringstream result;
		result << quadral(n*n);
		cout << alien(result.str()) << endl;
	}

	return 0;
}