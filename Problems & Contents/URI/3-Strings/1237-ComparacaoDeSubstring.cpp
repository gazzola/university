#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;





int subseq(string &x, string &y){

	int m = x.size();
	int n = y.size();

	int maior = 0;
	for(int i=0; i<m; i++){

		int k = i;
		int t = 0;

		for(int j=0; j<n; j++){
			if(x[k] == y[j]){
				t++;
				k++;
			}
			else{
				maior = max(maior, t);
				k = i;

				if(x[k] == y[j]){
					t = 1;
					k++;
				}
				else
					t = 0;
			}
		}

		maior = max(maior, t);

	}

	return maior;

}


int main(){

	
	string x, y;

	while(getline(cin, x) and getline(cin, y)){
		printf("%d\n", subseq(x, y));
	}


	return 0;
}