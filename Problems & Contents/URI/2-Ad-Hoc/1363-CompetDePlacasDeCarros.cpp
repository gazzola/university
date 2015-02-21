#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

typedef long long signed int lls;


int ctoi(char c){
	return (int) c - '0';
}

int ctod(char c){
	return (int) c - 'A';
}

bool temLetra(char c){
	if(c == 'A')
		return false;
	if(c == 'C')
		return false;
	if(c == 'M')
		return false;
	if(c == 'I')
		return false;
	if(c == 'P')
		return false;

	return true;
}


bool placaValida(char *si, int t){

	if(t == 5){
		for(int i=0; i<t; i++)
			if(!temLetra(si[i]))
				return false;
	}

	return true;
	
}


lls getNumber(char *from, lls *base10, lls *base26, map<char, int> &aux){
	
	int x = 0;
	int t = 0;

	while(from[t] >= 'A' and from[t] <= 'Z' and t < 7)
		t++;


	int t2 = t;
	while(from[t2] >= '0' and from[t2] <= '9' and t < 7)
		t2++;

	t2 -= t;


	if(t == 3 and t2 == 4){
		for(int i=0; i<t; i++)
			x = x*26 + ctod(from[i]);

		for(int i=t; i<7; i++)
			x = x*10 + ctoi(from[i]);

		return x;
	}
	else if(t == 5 and t2 == 2){

		for(int i=0; i<t; i++){
			if(!temLetra(from[i]))
				return -1;
			x = x*21 + aux[from[i]];
		}

		for(int i=t; i<7; i++)
			x = x*10 + ctoi(from[i]);

		return base26[2]*base10[3] + x;
	}
	
	
	return -1;
}





int main(){
	

	char sm[7], si[7];
	int c;

	lls base10[7];
	lls base26[7];

	base10[0] = 10;
	base26[0] = 26;
	for(int i=1; i<7; i++){
		base10[i] = base10[i-1]*10;
		base26[i] = base26[i-1]*26;
	}

	
	map<char, int> aux;
	int last = 0;
	for(int i='A'; i<='Z'; i++)
		if(temLetra(i))
			aux[i] = last++;


	int n1, n2;
	while(scanf("%s%n %s%n %d", sm, &n1, si, &n2, &c) and sm[0] != '*'){


		lls nm = getNumber(sm, base10, base26, aux);
		lls ni = getNumber(si, base10, base26, aux);

		// printf("%d\n", nm);
		// printf("%d\n\n", ni);

	
		if(ni > nm+c or ni <= nm or ni == -1)
			printf("N\n");
		else
			printf("Y\n");
		
	}


	
	return 0;
}