#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;





void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortThreeValues(int *x, int *y, int *z){
	if(*x > *y)
		swap(&(*x), &(*y));

	if(*y > *z)
		swap(&(*y), &(*z));

	if(*x > *y)
		swap(&(*x), &(*y));
}


int myatoi(char c){

	if(c == 'T')
		return 10;

	if(c == 'J')
		return 11;

	if(c == 'Q')
		return 12;

	if(c == 'K')
		return 13;

	return (int) c - '0';
}


int setNaipe(char c){
	if(c == 'H')
		return 0;

	if(c == 'C')
		return 1;

	if(c == 'D')
		return 2;

	return 3;
}

char getNaipe(int pos){
	double x = pos/13.0;
	if(x <= 1)
		return 'H';

	if(x <= 2)
		return 'C';
	
	if(x <= 3)
		return 'D';
	
	return 'S';
}

int getCard(int pos){
	if(pos % 13 == 0)
		return 13;
	return pos % 13;
}


int cardToPos(int x, char c){

	int k = 0;
	if(c == 'C')
		k = 1;
	else if(c == 'D')
		k = 2;
	else if(c == 'S')
		k = 3;

	return 13*k + x;
}

char cardToChar(int x){
	if(x == 10)
		return 'T';
	if(x == 11)
		return 'J';
	if(x == 12)
		return 'Q';
	if(x == 13)
		return 'K';
	return x + '0';
}


int getOrdemPos(vector<int> &v, int z1, int z2, int z3){
	if(v[1] == z1 and v[2] == z2)
		return 1;
	else if(v[1] == z1 and v[2] == z3)
		return 2;
	else if(v[1] == z2 and v[2] == z1)
		return 3;
	else if(v[1] == z2 and v[2] == z3)
		return 4;
	else if(v[1] == z3 and v[2] == z1)
		return 5;
	return 6;
}





int main(){

	// int ordem[55];
	// for(int i=0; i<52; i++)
	// 	ordem[i+1] = (i%13)+1;

	int n, z1, z2, z3;
	char c, d;
	
	scanf("%d", &n);
	while(n--){
		
		scanf("\n");
		vector<int> cartas;

		for(int i=0; i<4; i++){
			scanf("%c%c ", &c, &d);
			cartas.push_back(cardToPos(myatoi(c), d));
		}

		z1 = cartas[1];
		z2 = cartas[2];
		z3 = cartas[3];

		sortThreeValues(&z1, &z2, &z3);
		int j = getOrdemPos(cartas, z1, z2, z3);
		int y = getCard(cartas[0]+j);
		printf("%c%c\n", cardToChar(y), getNaipe(cartas[0]));
	}

	
	return 0;
}