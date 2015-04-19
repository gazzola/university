#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int ctoi(char c){
	return (int) c - '0';
}

bool ehBissexto(int ano){
	return ((ano % 4 == 0 and ano % 100 != 0) or ano % 400 == 0);
}

bool ehHuluculu(int ano){
	return (ano % 15 == 0);
}

bool ehBulukulu(int ano){
	return (ehBissexto(ano) and ano % 55 == 0);
}


int main(){
	

	char s[1001];
	int n;
	int dl1, dl2, dh, db;
	int l1, l2, h, b;
	bool linha = false;

	while(scanf("%s%n\n", s, &n) != EOF){
		
		dl1 = dl2 = dh = db = 1;
		l1 = l2 = h = b = 0;

		for(int i=n-1; i>=0; i--){

			l1 = (l1+(ctoi(s[i])*dl1) % 4) % 4;
			l2 = (l2+(ctoi(s[i])*dl2) % 400) % 400;
			h = (h+(ctoi(s[i])*dh) % 15) % 15;
			b = (b+(ctoi(s[i])*db) % 55) % 55;

			dl1 = (dl1*10)%4;
			dl2 = (dl2*10)%400;
			dh = (dh*10)%15;
			db = (db*10)%55;
		}

		bool div100 = (s[n-1] == '0' and s[n-2] == '0');
		if(linha)
			printf("\n");

		bool isLeap = ((l1 == 0 and !div100) or l2 == 0);
		bool isHuluculu = (h == 0);
		bool isBulukulu = (isLeap and b == 0);

		if(isLeap)
			printf("This is leap year.\n");

		if(isHuluculu)
			printf("This is huluculu festival year.\n");

		if(isBulukulu)
			printf("This is bulukulu festival year.\n");

		if(!isLeap and !isBulukulu and !isHuluculu)
			printf("This is an ordinary year.\n");

		linha = true;
	}


	return 0;
}