#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


typedef long long unsigned int llu;
typedef pair<llu, llu> ii;
typedef pair<vector<llu>, vector<llu>> vv;
typedef pair<llu, vector<llu>> vi;

// const llu LIM = 10000005;
const llu LIM = 10000005;
const int TAM = (1 << 12) - 1;
const llu MAX = 1000000000000; //10^12


bool isprime[LIM];
llu prime[LIM];
llu prime_cont = 1;

void crivo(){
	prime[0] = 2;
	memset(isprime, true, sizeof(isprime));

	for(llu i=3; i<=LIM; i+=2){
		if(isprime[i]){
			prime[prime_cont++] = i;
			for(llu j=i*i; j<=LIM; j+=i) 
				isprime[j] = false;
		}
	}
}



void factorize(llu n, vector<llu> &factors){
	
	for(unsigned int i=0; i<prime_cont; i++){

		llu p = prime[i];
		if(p*p > n)
			break;

		while(n % p == 0){
			n /= p;
			factors.push_back(p);
		}
			
	}

	if(n > 1)
		factors.push_back(n);
}

llu firstFactor(llu n){
	
	for(unsigned int i=0; i<prime_cont; i++){

		llu p = prime[i];
		if(p*p > n)
			break;

		while(n % p == 0)
			return p;
	}

	return n;
}


vector<ii> gerarBinarios(){

	queue<string> q;
	// vector<llu> v;
	// vector<llu> xp;
	vector<ii> d;
	llu x;

	q.push("1");

	while(true){
		string s1 = q.front();
		q.pop();

		x = stoll(s1);
		if(x >= MAX)
			break;

		// xp.clear();
		// factorize(x, xp);
		// cout << x << ": ";
		// for(int i=0; i<(int) xp.size(); i++)
		// 	cout << xp[i] << " ";
		// cout << endl;

		if(x != 1)
			d.push_back(ii(x, firstFactor(x)));
		
		string s2 = s1;
		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}

	return d;
}




bool orderBy(const ii &x, const ii &y){

	
	// if(x.second > y.second)
	// 	return false;
	// else if(x.second < y.second)
	// 	return true;
	
	return x.first < y.first;
}

bool orderBy2(const ii &x, const ii &y){

	
	// if(x.second > y.second)
	// 	return false;
	// else if(x.second < y.second)
	// 	return true;
	
	return x.first < y.first;
}







void buscarIndices(vector<vi> &bins, llu x, int &i, int &n){

	int ini=0, meio=0, fim=bins.size()-1;
	while(ini <= fim){
		meio = (ini+fim)/2;
		if(bins[meio].second[0] == x)
			break;
		else if(bins[meio].second[0] > x)
			fim = meio-1;
		else
			ini = meio+1;
	}

	if(bins[meio].second[0] == x){

		int p, q;
		p = q = meio;

		while(p>=0 and bins[p-1].second[0] == x)
			p--;
		i = p;
		
		while(q<n and bins[q+1].second[0] == x)
			q++;
		n = q;
	}
	else{
		i = 1;
		n = bins.size()-1;
	}
}



llu buscaFator(vector<ii> &bins, int f, llu x){

	int i, n;
	// buscarIndices(bins, f[0], i, n);
	// cout << i << " " << n << endl;
	
	i = f;
	n = (int) bins.size()-1;
	
	while(i <= n){
		if(bins[i].first % x == 0)
			return bins[i].first;
		i++;
	}

	return MAX;
}


int buscaBinaria(vector<ii> &bins, llu x){
	int ini=0, meio=0, fim=bins.size()-1;
	while(ini <= fim){
		meio = (ini+fim)/2;
		if(bins[meio].first == x)
			return meio;
		else if(bins[meio].first > x)
			fim = meio-1;
		else
			ini = meio+1;
	}
	return meio;
}


int main(){
	


	// vector<llu> divs;
	vector<ii> bins, bins2;
	map<llu, int> posbins;
	
	crivo();
	bins = gerarBinarios();
	bins2 = bins;
	// cout << bins.size() << endl;

	sort(bins.begin(), bins.end(), orderBy);
	sort(bins2.begin(), bins2.end(), orderBy2);
	for(int i=0; i<(int)bins2.size(); i++)
		posbins[bins2[i].first] = i;


	// for(int i=0; i<(int) bins.size(); i++){
	// 	cout << bins[i].first << ": ";
	// 	for(int j=0; j<(int) bins[i].second.size(); j++)
	// 		cout << bins[i].second[j] << " ";
	// 	cout << endl;
	// }

	// vector<ii> facs = binFactors(bins);

	
	llu n, f;

	while(scanf("%llu", &n) != EOF){
		
		if(n == 1){
			printf("1\n");
			continue;
		}

		if(n%9 == 1){
			printf("-1\n");
			continue;
		}

		
		// f = firstFactor(n);
		
		int p = buscaBinaria(bins, n);
		p = posbins[bins[p].first];
		llu x = buscaFator(bins2, p, n);
		if(x == MAX)
			printf("-1\n");
		else
			printf("%llu\n", x);

	}

	return 0;
}