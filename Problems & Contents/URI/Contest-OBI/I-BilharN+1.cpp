#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int distancia(int x1, int y1, int x2, int y2){
	int x = x2-x1;
	int y = y2-y1;
	return sqrt((x*x) + (y*y));
}



int main(){
	
	
	int c, n, x, y;
	ii branca;

	scanf("%d", &c);
	while(c--){

		vector<ii> bolas;
		scanf("%d %d %d", &n, &branca.first, &branca.second);


		int bprox = 0;
		for(int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			bolas.push_back(ii(x, y));
			
			int d1 = distancia(bolas[i].first, bolas[i].second, branca.first, branca.second);
			int d2 = distancia(bolas[bprox].first, bolas[bprox].second, branca.first, branca.second);
			if(d1 < d2)
				bprox = i;

		}

		printf("%d\n", bprox+1);
	}

	return 0;
}
