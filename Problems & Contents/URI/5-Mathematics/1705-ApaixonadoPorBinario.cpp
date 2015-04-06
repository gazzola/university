#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


typedef long long unsigned int llu;
typedef pair<llu, llu> ii;

const int TAM = 1 << 12;

vector<llu> gerarBinarios(int n){

	queue<string> q;
	vector<llu> v;


	q.push("1");

	while(n--){
		string s1 = q.front();
		q.pop();

		v.push_back(stoll(s1));
		
		string s2 = s1;
		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}

	return v;
}

bool ehPrimo(llu x){

	if(x == 2 or x == 3)
		return true;

	if(x % 2 == 0 or x < 2 or x % 3 == 0)
		return false;

	if(x < 9)
		return true;

	llu i = 5;
	while(i*i <= x){
		if(x%i == 0 or x%(i+2) == 0)
			return false;
		i += 6;
	}

	return true;
}


int acharI(int x, vector<llu> &divs){

	int ini=1, fim=divs.size(), meio=0;
	llu n = x;

	while(ini < fim){

		meio = (ini+fim)/2;

		if((divs[meio-1] <= n and divs[meio] >= n) or (divs[meio] <= n and divs[meio+1] >= n))
			return meio;
		else if(divs[meio] > n)
			fim = meio-1;
		else
			ini = meio+1;
	}

	return 1;
}

llu acharMenorMultiplo(llu x, vector<ii> &vet){
	int ini = 0, meio, fim = 74012;
	while(ini <= fim){
		meio = (ini+fim)/2;
		if(vet[meio].first == x)
			return vet[meio].second;
		else if(vet[meio].first < x)
			ini = meio+1;
		else
			fim = meio-1;
	}

	return 0;
}

bool ehBinarioDecimal(llu x){
	
	llu p = 1;
	int d; 

	while(x/p > 0){
		d = x%(p*10) / p;
		if(d > 1)
			return false;
		p *= 10;
	}


	return true;
}




int main(){
	


	// map<llu, int> vis;
	
	// vector<llu> divs = gerarBinarios(TAM);
	// vector<ii> primedivs;
	// set<llu> foi;
	

	// for(int i=0; i<(int) divs.size(); i++){
	// 	for(llu j=2; j*j<=divs[i]; j++){
	// 		if(divs[i]%j == 0){
	// 			if(vis.count(j) == 0){
	// 				vis[j] = 1;
	// 				primedivs.push_back(ii(j, divs[i]));
	// 			}

	// 			if(vis.count(divs[i]/j) == 0){
	// 				vis[divs[i]/j] = 1;
	// 				primedivs.push_back(ii(divs[i]/j, divs[i]));
	// 			}
	// 		}
	// 	}
	// }

	// // printf("%d\n\n", (int)primedivs.size());
	// sort(primedivs.begin(), primedivs.end());

	// for(int i=0; i<(int) primedivs.size(); i++){
	// 	printf("bindivs.push_back(ii(%llu, %llu)); ", primedivs[i].first, primedivs[i].second);
	// }

	// ii bindivs[74013];
	vector<ii> bindivs;



	llu n, k;

	while(scanf("%llu", &n) != EOF){
		
		if(ehBinarioDecimal(n)){
			printf("%llu\n", n);
			continue;
		}

		k = acharMenorMultiplo(n, bindivs);
		if(k > 0)
			printf("%llu\n", k);
		else
			printf("-1\n");

	}

	return 0;
}