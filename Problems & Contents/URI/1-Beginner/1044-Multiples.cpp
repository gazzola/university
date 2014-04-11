#include <iostream>

using namespace std;

int max(int *a, int *b){
	return (*a > *b) ? *a : *b;
}

int min(int *a, int *b){
	return (*a < *b) ? *a : *b;
}


int main(){

	int a, b;
	cin >> a >> b;

	if(max(&a, &b) % min(&a, &b) == 0)
		cout << "Sao Multiplos" << endl;
	else
		cout << "Nao sao Multiplos" << endl;
	

	return 0;
}