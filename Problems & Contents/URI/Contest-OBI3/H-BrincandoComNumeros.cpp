#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


typedef long long unsigned int llu;

const llu M = 10000000000000;



llu getMenorNumPossivel(llu x){

	vector<int> v;

	while(x > 0){
		v.push_back((int) (x % 10));
		x /= 10;
	}

	sort(v.begin(), v.end());


	llu y = 0, r = 1;
	for(int i=v.size()-1; i>=0; i--){
		y += v[i]*r;
		r *= 10;
	}

	return y;
}


llu getMaiorNumPossivel(llu x){

	vector<int> v;

	while(x > 0){
		v.push_back((int) (x % 10));
		x /= 10;
	}

	sort(v.begin(), v.end());


	llu y = 0, r = 1;
	for(int i=0; i<(int) v.size(); i++){
		y += v[i]*r;
		r *= 10;
	}

	return y;
}


int buscaBinaria(vector<llu> v, llu x){

	int ini = 0, meio, fim = v.size()-1;
	while(ini <= fim){
		meio = (ini+fim)/2;
		

		if(v[meio] == x)
			return meio;
		else if(v[meio-1] < x and v[meio+1] > x)
			return meio;
		else if(v[meio] > x)
			fim = meio-1;
		else
			ini = meio+1;
	}

	return 0;
}


bool temOsMesmosDigitos(llu num1, llu num2){
	int digits[10];
	int i;

	for (i = 0; i < 10; i++)
		digits[i] = 0;

	while (num1 != 0) {     
		digits[num1%10]++;  
		num1 /= 10;         
	}

	while (num2 != 0) {     
		digits[num2%10]--;
		num2 /= 10;
	}

	for (i = 0; i < 10; i++)
		if (digits[i] != 0) 
			return false;

	return true;
}



int main(){
	

	llu n, x, y;
	
	vector<llu> quadPerfeitos;
	for(llu i=0; ; i++){
		if(i*i >= M)
			break;
		quadPerfeitos.push_back(i*i);
	}

	scanf("%llu", &x);

	llu menor = getMenorNumPossivel(x);
	llu maior = getMaiorNumPossivel(x);

	
	int i = buscaBinaria(quadPerfeitos, menor+x);
	int count = 0;

	while(true){
		if(quadPerfeitos[i] < x){
			i++;
			continue;
		}

		if((quadPerfeitos[i]-x) > maior)
			break;
		
		y = quadPerfeitos[i]-x;
		if(temOsMesmosDigitos(x, y))
			count++;

		i++;
	}

	printf("%d\n", count);

}
