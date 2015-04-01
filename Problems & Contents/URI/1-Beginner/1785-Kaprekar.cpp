#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> ordenar_numero(int x){
	
	vector<int> vals;
	if(x < 10){
		vals.push_back(x);
		vals.push_back(0);
		vals.push_back(0);
		vals.push_back(0);
	}
	else if(x < 100){
		vals.push_back(x%10);
		vals.push_back(x%100 / 10);
		vals.push_back(0);
		vals.push_back(0);
	}
	else if(x < 1000){
		vals.push_back(x%10);
		vals.push_back(x%100 / 10);
		vals.push_back(x%1000 / 100);
		vals.push_back(0);
	}
	else{
		vals.push_back(x%10);
		vals.push_back(x%100 / 10);
		vals.push_back(x%1000 / 100);
		vals.push_back(x%10000 / 1000);
	}

	sort(vals.begin(), vals.end());
	return vals;
}



int maior_numero_com_digitos_de(int x){
	vector<int> vals = ordenar_numero(x);
	int a = vals[3]*1000;
	int b = vals[2]*100;
	int c = vals[1]*10;
	int d = vals[0];
	return a+b+c+d;
}

int menor_numero_com_digitos_de(int x){
	vector<int> vals = ordenar_numero(x);
	int a = vals[0]*1000;
	int b = vals[1]*100;
	int c = vals[2]*10;
	int d = vals[3];
	return a+b+c+d;
}


bool ver_loop(int x){

	if(x == 0)
		return true;

	vector<int> vals = ordenar_numero(x);
	if(vals[3] == vals[2] and vals[2] == vals[1] and vals[1] ==vals[0])
		return true;
	return false;
}




int krapekar(int X) {

	int cnt = 0;

	while (X != 6174){
		
		if(ver_loop(X))
			return -1;

		int maior = maior_numero_com_digitos_de(X);
		int menor = menor_numero_com_digitos_de(X);
		X = maior - menor;
		
		cnt = cnt + 1;
	}

	return cnt;

}

 
int main(){
 
	int t, x;
	
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		scanf("%d", &x);
		printf("Caso #%d: %d\n", i, krapekar(x));
	}
 
 
	return 0;
}