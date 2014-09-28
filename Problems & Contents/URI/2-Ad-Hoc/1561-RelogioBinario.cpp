#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;

void bin(int n, int d, char *buffer){
	int j=0;
	d--;
	for (int i=1<<d; i>0; i/=2)
		buffer[j++] = (n & i) ? 'o' : ' ';
}


void desenhar(char *buffer1, char *buffer2){
	printf(" ____________________________________________\n");
	printf("|                                            |\n");
	printf("|    ____________________________________    |_\n");
	printf("|   |                                    |   |_)\n");
	printf("|   |   8         4         2         1  |   |\n");
	printf("|   |                                    |   |\n");
	printf("|   |   %c         %c         %c         %c  |   |\n", buffer1[0], buffer1[1], buffer1[2], buffer1[3]);
	printf("|   |                                    |   |\n");
	printf("|   |                                    |   |\n");
	printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n", buffer2[0], buffer2[1], buffer2[2], buffer2[3], buffer2[4], buffer2[5]);
	printf("|   |                                    |   |\n");
	printf("|   |   32    16    8     4     2     1  |   |_\n");
	printf("|   |____________________________________|   |_)\n");
	printf("|                                            |\n");
	printf("|____________________________________________|\n");
	printf("\n");
}


int main(){

	char buffer1[10], buffer2[10];
	int h, m;
	while(scanf("%d:%d", &h, &m) != EOF){
		bin(h, 4, buffer1);
		bin(m, 6, buffer2);
		desenhar(buffer1, buffer2);
	}


	return 0;
}