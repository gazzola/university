#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


int getPos(int *v, int size){
	int bigger=0, posbigger;
	for(int i=0; i<size; i++){
		if(v[i] > bigger){
			bigger = v[i];
			posbigger = i;
		}
	}

	int sbigger = 0, possbigger;
	for(int i=0; i<size; i++){
		if(v[i] > sbigger && i != posbigger){
			sbigger = v[i];
			possbigger = i;
		}
	}

	return possbigger+1;
}


int main(){

	int n, x, count, pos;
	bool first;

	while(true){

		cin >> n;
		if(n == 0)
			break;

		int *v = new int[n];
		count = 0;
		while(n--){
			cin >> x;
			v[count] = x;
			count++;
		}

		pos = getPos(v, count);
		cout << pos << endl;
		
		delete[] v;
	}


	return 0;
}