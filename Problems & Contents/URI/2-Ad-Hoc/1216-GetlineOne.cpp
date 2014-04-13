#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


int main(){
	
	string name, x;
	int n, sumkg=0;
	double value, sum=0;

	

	cin >> n;
	
	for(int i=0; i<n; i++){

		int kg = 1;

		cin >> value;
		getline(cin, name);
		getline(cin, name);
		
		int tam = name.size();

		for(int j=0; j<tam; j++)
			if(name[j] == ' ')
				kg++;

		cout << "day " << i+1 << ": " << kg << " kg" << endl;
		sum += value;
		sumkg += kg;
	}

	cout << fixed << setprecision(2); 
	cout << double(sumkg)/n << " kg by day" << endl;
	cout << "R$ " << sum/n << " by day" << endl;

	

	return 0;
}