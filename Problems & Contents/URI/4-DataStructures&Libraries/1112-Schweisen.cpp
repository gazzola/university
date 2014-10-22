#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
 
using namespace std;
 
 
const int MAX = 1001;
int MAX_X, MAX_Y, P;
 
int tree[MAX][MAX];
 
void atualiza(int x, int y, int val){
	while (x <= MAX_X){
		int y1 = y;
		while(y1 <= MAX_Y){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}
  
  
int le(int x, int y){
	int sum = 0;
 
	while (x > 0){
		int y1 = y;
		while(y1 > 0){
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
 
	}
 
	return sum;
}
  

int selecao(int x, int y, int z, int w){
	 
	int x1 = min(x, z);
	int x2 = max(x, z);
	int y1 = min(y, w);
	int y2 = max(y, w);
	 
 
	//return le(x2,y2) - min(x1, y1);
	int s = le(x2, y2);
	s -= le(x2, y1-1);
	s -= le(x1-1, y2);
	s += le(x1-1, y1-1);
 
	return s;
 
	 
}
 
 
	 
 
int main(){
 	
	int q, n, x, y, z, w;
	char c;

	while(true){
		 
		scanf("%d %d %d", &MAX_X, &MAX_Y, &P);
 
		if(MAX_X == MAX_Y and MAX_Y == P and P == 0)
			break;
 
		//for(int i=1; i<=MAX_X; i++)
		//	for(int j=1; j<=MAX_Y; j++)
		//		tree[i][j] = 0;
		

		int m = max(MAX_Y+1, MAX_X+1);
 		memset(tree, 0, sizeof(tree[0][0]) * m * MAX);


		scanf("%d", &q);
		 
		while(q--){
 
			scanf("\n%c", &c);
			if(c == 'A'){
				scanf("%d %d %d", &n, &x, &y);
				atualiza(x+1, y+1, n);
			}
			else{
				scanf("%d %d %d %d", &x, &y, &z, &w);
				int res = selecao(x+1, y+1, z+1, w+1)*P;
				printf("%d\n", res);
			}
 
		}
 
		printf("\n");
	}
 
}