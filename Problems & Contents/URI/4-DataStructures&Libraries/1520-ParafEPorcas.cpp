#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
 
using namespace std;
 


int procurar(vector<int> &inters, int x){
	
	int ini = 0;
	int meio = 0;
	int fim = inters.size()-1;

	while(ini <= fim){
		meio = (ini+fim)/2;

		if(inters[meio] == x)
			return meio;
		else if (inters[meio] < x) 
			ini = meio + 1;
		else 
			fim = meio - 1;
	}

	return -1;
}

void acharLimites(vector<int> &inters, int pos, int x, int *i, int *j){
	*i = pos;
	while(inters[*i - 1] == x)
		(*i)--;

	*j = pos;
	while(inters[*j + 1] == x)
		(*j)++;
}
 
int main(){
 
	int n;

	while(scanf("%d", &n) != EOF){

		int x, y;
		vector<int> inters;

		while(n--){
			scanf("%d %d", &x, &y);
			for(int i=x; i<=y; i++)
				inters.push_back(i);
		}

		sort(inters.begin(), inters.end());

		int num;
		scanf("%d", &num);

		int pos = procurar(inters, num);

		if(pos >= 0){
			int i, j;
			acharLimites(inters, pos, num, &i, &j);
			printf("%d found from %d to %d\n", num, i, j);
		}
		else
			printf("%d not found\n", num);


	}
 
	return 0;
}