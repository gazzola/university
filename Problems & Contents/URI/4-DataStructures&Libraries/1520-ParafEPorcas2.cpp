#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
 
using namespace std;
 


 
int main(){
 
	int n;

	while(scanf("%d", &n) != EOF){

		int x, y;
		int inters[101];
		memset(inters, 0, sizeof(inters));
		
		while(n--){
			scanf("%d %d", &x, &y);
			for(int i=x; i<=y; i++)
				inters[i]++;
		}

	
		int num;
		scanf("%d", &num);

		int pos = inters[num];

		if(pos > 0){
			
			int s = 0;
			for(int i=num-1; i>=0; i--)
				s += inters[i];

			int t = s+inters[num]-1;

			printf("%d found from %d to %d\n", num, s, t);
		}
		else
			printf("%d not found\n", num);


	}
 
	return 0;
}