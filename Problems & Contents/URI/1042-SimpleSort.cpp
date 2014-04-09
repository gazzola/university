#include <iostream>
#include <iomanip>

using namespace std;


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortThreeValues(int *v){
	if(v[0] > v[1])
		swap(v[0], v[1]);

	if(v[1] > v[2])
		swap(v[1], v[2]);

	if(v[0] > v[1])
		swap(v[0], v[1]);
}


int main(){

	
	int v[3], v2[3];

	for(int i=0; i<3; i++){
		cin >> v[i];
		v2[i] = v[i];
	}

	sortThreeValues(v);

	for(int i=0; i<3; i++)
		cout << v[i] << endl;

	cout << endl;

	for(int i=0; i<3; i++)
		cout << v2[i] << endl;


	return 0;
}