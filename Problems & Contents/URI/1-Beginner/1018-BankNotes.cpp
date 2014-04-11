#include <iostream>

using namespace std;



int main(){

	unsigned int n, result[7];

	cin >> n;


	cout << n << endl;
	for(int i=0, note=100; i<7; ++i, note/=2){
		
		if(note == 25)
			note = 20;

		result[i] = n/note;
		n -= result[i]*note;

		cout << result[i] << " nota(s) de R$ " 
			 << note << ",00" << endl;
	}

	return 0;
}