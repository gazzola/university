#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


char animais[111] = {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'd', 'd', 'd', 'd', 'e', 'e', 'e', 'e', 'f', 'f', 'f', 'f', 'g', 'g', 'g', 'g', 'h', 'h', 'h', 'h', 'i', 'i', 'i', 'i', 'j', 'j', 'j', 'j', 'k', 'k', 'k', 'k', 'l', 'l', 'l', 'l', 'm', 'm', 'm', 'm', 'n', 'n', 'n', 'n', 'o', 'o', 'o', 'o', 'p', 'p', 'p', 'p', 'q', 'q', 'q', 'q', 'r', 'r', 'r', 'r', 's', 's', 's', 's', 't', 't', 't', 't', 'u', 'u', 'u', 'u', 'v', 'v', 'v', 'v', 'w', 'w', 'w', 'w', 'x', 'x', 'x', 'x', 'y', 'y', 'y', 'y', 'z', 'z', 'z', 'z'};

void setNovo(char *novo, char *old, int *size){
	int tam = strlen(old);
	if(tam == 1){
		*size = tam+3;
		strcpy(novo, "000");
		strcat(novo, old);
	}
	else if(tam == 2){
		*size = tam+2;
		strcpy(novo, "00");
		strcat(novo, old);
	}
	else if(tam == 3){
		*size = tam+1;
		strcpy(novo, "0");
		strcat(novo, old);
	}
	else{
		*size = tam;
		strcpy(novo, old);
	}
}


bool intervaloAnimal(char a1, char a2, char b1, char b2){

	char novoa[3];
	char novob[3];

	novoa[0] = a2;
	novoa[1] = a1;
	novoa[2] = '\0';

	novob[0] = b2;
	novob[1] = b1;
	novob[2] = '\0';

	int numa = atoi(novoa);
	int numb = atoi(novob);

	if(numa == 0)
		numa = 100;
	if(numb == 0)
		numb = 100;

	numa--;
	numb--;

	return animais[numa] == animais[numb];
}


double calcular(double v, char *n, char *m, int size1, int size2){

	int size = min(size1, size2);
	int ini = size-1;
	int fim = ini-3;
	int count = 0;

	int i = size1-1;
	int j = size2-1;

	//printf("%d %d\n", ini, fim);
	//printf("%s %s\n", n, m);

	for(int k=ini; k>=fim; k--, i--, j--){
		if(n[i] == m[j])
			count++;
		else
			break;
	}



	if(count == 2)
		return v*50;
	else if(count == 3)
		return v*500;
	else if(count == 4)
		return v*3000;
	
	char a1 = n[size1-1];
	char a2 = n[size1-2];

	char b1 = m[size2-1];
	char b2 = m[size2-2];
	if(intervaloAnimal(a1, a2, b1, b2))
		return v*16;


	return 0.00;

}



int main(){
	

	double v;

	char n[8];
	char m[8];

	while(scanf("%lf %s %s", &v, n, m) and v > 0){

		char novon[8];
		char novom[8];
		int size1 = 0;
		int size2 = 0;

		setNovo(novon, n, &size1);
		setNovo(novom, m, &size2);


		double total = calcular(v, novon, novom, size1, size2);

		printf("%.2lf\n", total);

	}
	
	
	return 0;
}