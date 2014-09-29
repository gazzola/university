#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



void printMensagemBraile(char *numMsg, char numToBraile[10][7], int d){
	
	int pos = numMsg[0] - '0';
	printf("%c%c", numToBraile[pos][0], numToBraile[pos][1]);

	for(int i=1; i<d; i++){
		pos = numMsg[i] - '0';
		printf(" %c%c", numToBraile[pos][0], numToBraile[pos][1]);
	}

	printf("\n");

	pos = numMsg[0] - '0';
	printf("%c%c", numToBraile[pos][2], numToBraile[pos][3]);
	for(int i=1; i<d; i++){
		pos = numMsg[i] - '0';
		printf(" %c%c", numToBraile[pos][2], numToBraile[pos][3]);
	}

	printf("\n");

	pos = numMsg[0] - '0';
	printf("%c%c", numToBraile[pos][4], numToBraile[pos][5]);
	for(int i=1; i<d; i++){
		pos = numMsg[i] - '0';
		printf(" %c%c", numToBraile[pos][4], numToBraile[pos][5]);
	}

	printf("\n");
}


void printMensagemNum(char braileMsg[102][7], map<string, int> &braileToNum, int d){
	string strcpp;
	for(int i=0; i<d; i++){
		strcpp = braileMsg[i];
		printf("%d", braileToNum[strcpp]);
	}

	printf("\n");
}



int main(){
	

	char numToBraile[10][7] = {".***..", "*.....", "*.*...", "**....", "**.*..", 
					  	   "*..*..", "***...", "****..", "*.**..", ".**..."};
	
	map<string, int> braileToNum;
	braileToNum[".***.."] = 0;
	braileToNum["*....."] = 1;
	braileToNum["*.*..."] = 2;
	braileToNum["**...."] = 3;
	braileToNum["**.*.."] = 4;
	braileToNum["*..*.."] = 5;
	braileToNum["***..."] = 6;
	braileToNum["****.."] = 7;
	braileToNum["*.**.."] = 8;
	braileToNum[".**..."] = 9;


	int d;
	char c;
	char numMsg[102];
	char braileMsg[102][7];

	while(scanf("%d", &d) and d != 0){

		scanf("\n%c\n", &c);

		if(c == 'S'){
			scanf("%s", numMsg);
			printMensagemBraile(numMsg, numToBraile, d);

		}
		else{			
			for(int i=0; i<3; i++){
				for(int j=0; j<d; j++){

					char c1, c2;					
					scanf("%c%c", &c1, &c2);

					int pc = i*2;
					braileMsg[j][pc] = c1;
					braileMsg[j][pc+1] = c2;

					scanf("%c", &c);
					braileMsg[j][6] = '\0';
				}


			}

			printMensagemNum(braileMsg, braileToNum, d);
		}

	}


	
	return 0;
}