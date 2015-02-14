#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;


int ctoi(char c){
	return (int) c - '0';
}


int binToInt(char *bin){
	int t = 0;
	t += ctoi(bin[7]);
	t += ctoi(bin[6])*2;
	t += ctoi(bin[5])*4;
	t += ctoi(bin[4])*8;
	t += ctoi(bin[3])*16;
	t += ctoi(bin[2])*32;
	t += ctoi(bin[1])*64;
	t += ctoi(bin[0])*128;
	return t;
}


int main(){
	

	int memoria[32];
	char instrucao[8];
	bool fim;
	short int accu, pc;
	
	while(true){

		if(scanf("%s", instrucao) == EOF)
			break;

		memoria[0] = binToInt(instrucao);

		for(int i=1; i<32; i++){
			scanf("%s", instrucao);
			memoria[i] = binToInt(instrucao);
		}


		accu = pc = 0;
		fim = false;

		while(!fim){

			int inst = memoria[pc] >> 5;
			int ender = memoria[pc] % 32;
			pc = (pc+1)%32;
			
			if(inst == 0){
				memoria[ender] = accu;
			}
			else if(inst == 1){
				accu = memoria[ender];
			}
			else if(inst == 2){
				if(accu == 0)
					pc = ender;
			}
			else if(inst == 3){
				continue;
			}
			else if(inst == 4){
				if(accu == 0)
					accu = 255;
				else
					accu--;
			}
			else if(inst == 5){
				accu = (accu+1) % 256;
			}
			else if(inst == 6){
				pc = ender;
			}
			else if(inst == 7)
				fim = true;
		}

		char result[8];
		for(int i=0; i<8; i++){
			result[7-i] = ((accu & 1) == 1) ? '1' : '0';
			accu >>= 1;
		}
		printf("%s\n", result);

	}
	
	
	
	
	return 0;
}