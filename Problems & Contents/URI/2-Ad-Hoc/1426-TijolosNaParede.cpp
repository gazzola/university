#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, mat[9][9];

	cin >> n;
	while(n--){

		for(int i=0; i<9; i+=2)
			for(int j=0; j<=i; j+=2)
				cin >> mat[i][j]; 

		
		for(int j=1; j<9; j+=2)
			mat[8][j] = (mat[6][j-1] - (mat[8][j-1]+mat[8][j+1]))/2;
		

		for(int i=7; i>=0; i--)
			for(int j=0; j<9; j++)
				if((i & 1) == 1 || (j & 1) == 1)
					mat[i][j] = mat[i+1][j] +mat[i+1][j+1];


		for(int i=0; i<9; i++){
			for(int j=0; j<=i; j++){
				if(j < i)
					cout << mat[i][j] << " ";
				else
					cout << mat[i][j];
			}
			cout << endl;
		}
	}
	

	return 0;
}