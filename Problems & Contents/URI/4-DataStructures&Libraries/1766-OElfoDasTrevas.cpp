#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct rena{

	string nome;
	int peso, idade;
	double altura;

	rena(){}
	rena(string nome, int peso, int idade, double altura){
		this->nome = nome;
		this->peso = peso;
		this->idade = idade;
		this->altura = altura;
	};

	bool operator < (const rena &r) const{

		if(this->peso < r.peso)
			return false;
		else if(this->peso > r.peso)
			return true;

		if(this->idade < r.idade)
			return true;
		else if(this->idade > r.idade)
			return false;

		if(this->altura < r.altura)
			return true;
		else if(this->altura > r.altura)
			return false;

		return this->nome < r.nome;
	};
	
}rena;


int main(){
 	
 	string nome;
	int peso, idade;
	double altura;
	
	int t, n, m;
	cin >> t;

	for(int c=1; c<=t; c++){

		vector<rena> treno;
		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++){
			cin >> nome >> peso >> idade >> altura;
			treno.push_back(rena(nome, peso, idade, altura));
		}

		sort(treno.begin(), treno.end());

		cout << "CENARIO {" << c << "}" << endl;
		for(int i=0; i<m; i++)
			cout << i+1 << " - " << treno[i].nome << endl;

	}
 
	return 0;
}