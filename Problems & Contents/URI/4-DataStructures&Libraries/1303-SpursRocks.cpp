#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
 
using namespace std;
 

typedef pair<int, double> id;

typedef struct _team{

	int id;
	int vitorias;
	int derrotas;

	int particip;

	int ptsMarcados;
	int ptsRecebidos;
	
	double media;
	// ptsMarcados / ptsRecebidos

}team;

bool orderBy(const team &x, const team &z){
	
	if(x.vitorias > z.vitorias)
		return true;
	else if(x.vitorias < z.vitorias)
		return false;
	

	double md1 = (x.ptsRecebidos == 0) ? x.ptsMarcados : (double) x.ptsMarcados/(double) x.ptsRecebidos;
	double md2 = (z.ptsRecebidos == 0) ? z.ptsMarcados : (double) z.ptsMarcados/(double) z.ptsRecebidos;
	if(md1 > md2)
		return true;
	else if(md1 < md2)
		return false;


	if(x.ptsMarcados > z.ptsMarcados)
		return true;
	else if(x.ptsMarcados < z.ptsMarcados)
		return false;


	return (x.particip < z.particip);
}

int main(){
 
	int n, inst=0;
	vector<team> times(101);

	while(true){

		scanf("%d", &n);
		
		if(n > 0){
			if(inst > 0)
				printf("\n");
		}
		else
			break;

		times[0].id = 0;
		times[0].vitorias = -1;
		times[0].derrotas = 9999;
		times[0].particip = 9999;
		times[0].ptsMarcados = -1;
		times[0].ptsRecebidos = 9999;
		times[0].media = 0.0;

		for(int i=1; i<=100; i++){
			times[i].id = i;
			times[i].vitorias = 0;
			times[i].derrotas = 0;
			times[i].particip = 0;
			times[i].ptsMarcados = 0;
			times[i].ptsRecebidos = 0;
			times[i].media = 0.0;
		}


		int l = n*(n-1)/2;
		int x, y, z, w;

		while(l--){
			scanf("%d %d %d %d", &x, &y, &z, &w);

			times[x].particip += 1;
			times[z].particip += 1;

			if(y > w){
				times[x].vitorias += 2;
				times[x].ptsMarcados += y;
				times[x].ptsRecebidos += w;

				times[z].derrotas += 1;
				times[z].ptsMarcados += w;
				times[z].ptsRecebidos += y;
			}
			else{
				times[z].vitorias += 2;
				times[z].ptsMarcados += w;
				times[z].ptsRecebidos += y;

				times[x].derrotas += 1;
				times[x].ptsMarcados += y;
				times[x].ptsRecebidos += w;
			}
		}


		sort(times.begin(), times.end(), orderBy);

		printf("Instancia %d\n", ++inst);

		printf("%d", times[0].id);
		for(int i=1; i<n; i++)
			printf(" %d", times[i].id);
		
		printf("\n");
	}
 
	return 0;
}