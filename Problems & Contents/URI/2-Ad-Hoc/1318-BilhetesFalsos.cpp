#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int n, m, x;

	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;

		int *bilhetes = new int[n+1]();
		for(int i=0; i<m; i++){
			cin >> x;
			bilhetes[x] += 1;
		}

		int total = 0;
		for(int i=1; i<=n; i++)
			if(bilhetes[i] > 1)
				total++;
		
		cout << total << endl;

		delete[] bilhetes;
		
	}

	return 0;
}