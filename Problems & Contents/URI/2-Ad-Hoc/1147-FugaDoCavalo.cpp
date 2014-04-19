#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;


int main(){
	
	int x, y, count=1, result, xtemp, ytemp;
	int mat[8][8];
	char c;

	while(true){
		scanf("%d%c", &x, &c);
		if(x == 0)
			break;

		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
				mat[i][j] = 1;

		x = 8-x;
		y = abs(97-c);

		for(int i=0; i<8; i++){
			scanf("%d%c", &xtemp, &c);
			xtemp = 8-xtemp;
			ytemp = abs(97-c);
			if(xtemp < 7 && ytemp > 0)
				mat[xtemp+1][ytemp-1] = 0;
			if(xtemp < 7 && ytemp < 7)
				mat[xtemp+1][ytemp+1] = 0;
		}

		
		result = 0;
		if(x-2 >= 0 && y-1 >= 0)
			result += mat[x-2][y-1];

		if(x-2 >= 0 && y+1 <= 7)
			result += mat[x-2][y+1];

		if(x-1 >= 0 && y-2 >= 0)
			result += mat[x-1][y-2];

		if(x-1 >= 0 && y+2 <= 7)
			result += mat[x-1][y+2];

		if(x+1 <= 7 && y-2 >= 0)
			result += mat[x+1][y-2];

		if(x+1 <= 7 && y+2 <= 7)
			result += mat[x+1][y+2];

		if(x+2 <= 7 && y-1 >= 0)
			result += mat[x+2][y-1];

		if(x+2 <= 7 && y+1 <= 7)
			result += mat[x+2][y+1];


		printf("Caso de Teste #%d: %d movimento(s).\n", count, result);
		count++;
	}

	
	return 0;
}