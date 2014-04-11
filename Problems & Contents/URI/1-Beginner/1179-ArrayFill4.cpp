#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 15


bool isOdd(int n){
	return ((n & 1) == 1);
}

void printEven(int *v, int n){
	for(int i=0; i<n; i++)
		cout << "par[" << i << "] = " << v[i] << endl;
}

void printOdd(int *v, int n){
	for(int i=0; i<n; i++)
		cout << "impar[" << i << "] = " << v[i] << endl;
}

int main(){

	int even[MAX], odd[MAX], ce=0, co=0, limit=5, x;

	for(int i=0; i<MAX; i++){
		
		cin >> x;
		if(isOdd(x)){
			odd[co] = x;
			co++;
			if(co == 5){
				printOdd(odd, co);
				co = 0;
			}
		}
		else{
			even[ce] = x;
			ce++;
			if(ce == 5){
				printEven(even, ce);
				ce = 0;
			}
		}
	}

	printOdd(odd, co);
	printEven(even, ce);

	return 0;
}