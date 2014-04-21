#include <iostream>
#include <iomanip>

using namespace std;


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int bubble(int *v, int *t, int n){
	
	int i, j, k=n-1, c=0;

	for(i=0; i<n; i++){
		for(j=0; j<k; j++){
			if(v[j] == t[i])
				swap(v[j], v[j+1]);
			else
				c++;
		}
		k--;
	}

	return c;
}


int main(){
	
	int n, x;

	while(cin >> n){

		int largada[25], chegada[25];

		for(int i=0; i<n; i++){
			cin >> x;
			largada[i] = x;
		}

		for(int i=0; i<n; i++){
			cin >> x;
			chegada[i] = x;
		}

		int count = bubble(chegada, largada, n);
		cout << count << endl;

	}

	return 0;
}