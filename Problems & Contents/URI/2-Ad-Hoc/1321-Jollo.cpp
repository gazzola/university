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

void sortTwoValues(int *x, int *y){
	if(*x > *y)
		swap(&(*x), &(*y));
}


int getMenor(vector<int> &cartas, int x){

	int i;
	for(i=0; i<5; i++)
		if(cartas[i] == x)
			break;

	for(int j=i; j<5; j++)
		if(cartas[j]+1 != cartas[j+1])
			return cartas[j]+1;

	return -1;
}


bool verifica(int *v, int *t, int jn){

	int perdeu = 0;
	int a = -1;
	int b = -1;

	// pior escolha eh a menor carta do principe
	// com a que eh so um pouco maior que ela
	for(int i=0; i<jn; i++){
		int x = t[i];
		for(int j=0; j<3; j++){
			if(v[j] > x and v[j] != a and v[j] != b){
				
				if(a == -1)
					a = v[j];
				
				if(b == -1)
					b = v[j];

				perdeu++;
				break;
			}
		}
	}

	return (perdeu > 1);
}



int main(){
	
	int v[3], t[3];

	while(scanf("%d %d %d %d %d", &v[0], &v[1], &v[2], &t[0], &t[1]) and v[0] > 0){

		sortThreeValues(&v[0], &v[1], &v[2]);
		sortTwoValues(&t[0], &t[1]);

		t[2] = -1;
		for(int i=1; i<=52; i++){
			if(v[0]!=i and v[1]!=i and v[2]!=i and t[0]!=i and t[1]!=i){
				t[2] = i;
				if(!verifica(v, t, 3))
					break;
				else
					t[2] = -1;
			}
		}

		printf("%d\n", t[2]);
	}
	
	return 0;
}