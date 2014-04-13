#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

 
int main(){
	 
	int n;
	while(true){
		
		cin >> n;
		if(n==0)
			break;
		
		int maior = n;
		while(n > 1){
			n = ((n & 1) == 0) ? n/2 : 3*n+1;
			if(n > maior)
				maior = n;
		}
		
		cout << maior << endl;
		
	}
	
	return 0;
}