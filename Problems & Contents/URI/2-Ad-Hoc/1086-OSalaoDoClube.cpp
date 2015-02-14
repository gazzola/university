#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long unsigned int llu;


int buscarTabua(vector<int> &tabuas, bool *colocados, int k, int x){

	int ini, meio, fim;
	ini = 0;
	fim = tabuas.size();

	while(ini < fim){

		meio = (ini+fim)/2;
		if(tabuas[meio]+tabuas[k] == x)
			break;
		else if(tabuas[meio]+tabuas[k] > x)
			fim = meio-1;
		else
			ini = meio+1;

	}

	if(!colocados[meio])
		return meio;


	int i = meio-1;
	int j = meio+1;

	while(tabuas[i]+tabuas[k] == x){
		if(!colocados[i])
			return i;
		i--;
	}

	while(tabuas[j]+tabuas[k] == x){
		if(!colocados[j])
			return j;
		j++;
	}

	return -1;

}


int main(){
	
	
	int m, n, l, t, x;
	int vertical, horizontal;
	
	bool colocadosH[100001];
	bool colocadosV[100001];

	int area;

	while(scanf("%d %d", &m, &n) and m > 0){

		m *= 100;
		n *= 100;

		area = m*n;
		scanf("%d", &l);
		scanf("%d", &t);


		vector<int> tabuas;
		for(int i=0; i<t; i++){
			scanf("%d", &x);
			tabuas.push_back(x*100);
			colocadosH[i] = false;
			colocadosV[i] = false;
		}


		sort(tabuas.begin(), tabuas.end());



		vertical = 0;
		horizontal = 0;
		int vArea = 0, hArea = 0;

		int i = 0;
		int k = t-1;
		bool okV = false, okH = false;

		if(m % l == 0){
			while(i < m and k >= 0){
				if(tabuas[k] == n){
					vArea += tabuas[k]*l;
					colocadosV[k] = true;
					vertical++;
					i += l;
				}
				else if(tabuas[k] < n){
					int j = buscarTabua(tabuas, colocadosV, k, n);
					if(j >= 0){
							vArea += tabuas[k]*l;
							vArea += tabuas[j]*l;
							colocadosV[j] = true;
							colocadosV[k] = true;
							vertical += 2;
							i += l;
					}
				}

				if(i == m)
					okV = true;

				k--;
			}
		}
		else
			vertical = 99999999;




		i = 0;
		k = t-1;

		if(n % l == 0){
			while(i < n and k >= 0){
				if(tabuas[k] == m){
					hArea += tabuas[k]*l;
					colocadosH[k] = true;
					horizontal++;
					i += l;
				}
				else if(tabuas[k] < m){
					int j = buscarTabua(tabuas, colocadosH, k, m);
					if(j >= 0){
							hArea += tabuas[k]*l;
							hArea += tabuas[j]*l;
							// hArea += (tabuas[k]+tabuas[j])*l;
							colocadosH[j] = true;
							colocadosH[k] = true;
							horizontal += 2;
							i += l;
					}
				}

				if(i == n)
					okH = true;

				k--;
			}
		}
		else
			horizontal = 99999999;



		if(okV and okH){
			if(vertical < horizontal){
				if(vArea == hArea)
					printf("%d\n", vertical);
				else
					printf("impossivel\n");
			}
			else
				printf("%d\n", horizontal);
			// printf("%d\n", min(vertical, horizontal));
		}
		else if(okV and !okH){
			if(vArea == area or vArea % m != 0)
				printf("%d\n", vertical);
			else
				printf("impossivel\n");
		}
		else if(!okV and okH){
			if(hArea == area or hArea % n != 0)
				printf("%d\n", horizontal);
			else
				printf("impossivel\n");
			
		}
		else
			printf("impossivel\n");

	}


	
	return 0;
}