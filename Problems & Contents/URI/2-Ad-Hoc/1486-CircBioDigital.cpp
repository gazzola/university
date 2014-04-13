#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int p, n, c;
	int matrix[1000][1000];

	while(true){

		cin >> p >> n >> c;
		if(p==0 && n==0 && c==0)
			break;

		for(int i=0; i<n; i++)
			for(int j=0; j<p; j++)
				cin >> matrix[i][j];

		int palitos = 0;
		for(int i=0; i<p; i++){
			int aux=0;
			for(int j=0; j<n; j++){
				if(matrix[j][i] == 1){
					aux++;
				}
				
				if(matrix[j][i] == 0){
					if(aux >= c)
						palitos++;

					aux=0;
				}
				else if(j == n-1){
					if(aux >= c)
						palitos++;
				}
				
			}
		}

		cout << palitos << endl;

	}

	return 0;
}