#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int myatoi(char c){
	return (int) c - '0';
}


int main(){
	
	char cpf[15];
	int k, b1, b2;
	bool ok;

	while(scanf("%s", cpf) != EOF){

		ok = true;

		b1 = 0;
		k = 1;
		for(int i=0; i<11; i++)
			if(cpf[i] != '.')
				b1 += myatoi(cpf[i])*(k++);


		b1 = (b1%11 == 10) ? 0 : b1%11;
		if(b1 != myatoi(cpf[12]))
			ok = false;


		if(ok){
			b2 = 0;
			k = 9;
			for(int i=0; i<11; i++)
				if(cpf[i] != '.')
					b2 += myatoi(cpf[i])*(k--);

			
			b2 = (b2%11 == 10) ? 0 : b2%11;
			if(b2 != myatoi(cpf[13]))
				ok = false;
		}


		if(ok)
			printf("CPF valido\n");
		else
			printf("CPF invalido\n");



	}


	
	return 0;
}