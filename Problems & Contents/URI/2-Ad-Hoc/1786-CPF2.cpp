#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int ctoi(char c){
	return (int) c - '0';
}


int main(){
	
	char cpf[15];
	int k, b1, b2;

	while(scanf("%s\n", cpf) != EOF){

		b1 = b2 = 0;
		
		k = 1;
		for(int i=0; i<9; i++)
			b1 += ctoi(cpf[i])*(k++);
		b1 = (b1%11 == 10) ? 0 : b1%11;


		k = 9;
		for(int i=0; i<9; i++)
			b2 += ctoi(cpf[i])*(k--);
		b2 = (b2%11 == 10) ? 0 : b2%11;
		
		printf("%c%c%c.", cpf[0], cpf[1], cpf[2]);
		printf("%c%c%c.", cpf[3], cpf[4], cpf[5]);
		printf("%c%c%c-", cpf[6], cpf[7], cpf[8]);
		printf("%d%d\n", b1, b2);
	}


	
	return 0;
}