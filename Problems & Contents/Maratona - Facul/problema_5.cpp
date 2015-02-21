#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>

using namespace std;


void printVector(vector<int> &v){
	int n = v.size();
	for(int i=1; i<=n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main(){
	
	int qtd, pos, pulo;
	int k;
	cin >> k;
	while(k--){
		cin >> qtd >> pos >> pulo;
		

		vector<int> circulo = vector<int>(qtd+1);
		for(int i=0; i<=qtd; i++)
			circulo[i]=i;
		
		while(circulo.size() > 2){
			pos = (pos+pulo-1) % (circulo.size()-1);
			circulo.erase(circulo.begin()+pos); 
		}

		printf("%d\n", circulo[0]);
	}

	return 0;
}


/*.


1 - 2 - 3 - 4 - 5 - 6 - 7
2 - 3 - 4 - 5 - 6 - 7
2 - 3 - 4 - 6 - 7
3 - 4 - 6 - 7
3 - 4 - 6
4 - 6
4
*/