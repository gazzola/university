#include <iostream>
#include <iomanip>

using namespace std;

bool isOdd(int n){
	return ((n & 1) == 1);
}

int max(int *a, int *b){
	return (*a > *b) ? *a : *b;
}

int min(int *a, int *b){
	return (*a < *b) ? *a : *b;
}


int main(){

	int a, b, init, final, sum=0;

	while(true){
		cin >> a >> b;
		
		if(a == 0 || b == 0)
			break;

		init = min(&a, &b);
		final = max(&a, &b);

		//sn = (n*(a1 + an))/2
		sum = ((final-init+1)*(init + final))/2;

	    for(int i=init; i<=final; i++){
	    	cout << i << " ";
	    	//sum += i;
	    }

	    cout << "Sum=" << sum << endl;
	    sum = 0;
	}

	return 0;
}