#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;




bool ehSomaDQ2_ForcaBruta(int n){

	int max = sqrt(n);

	for(int i=0; i<=max; i++){
		if(i*i == n)
			return true;
		for(int j=i; j<=max; j++)
			if(i*i + j*j == n)
				return true;
	}

	return false;

}

bool ehSomaDQ_BuscaBinaria(int n){

	if(n < 0)
		return false;

	float max2 = sqrt(n);
	int max = (int) max2;
	
	if(max == max2)
		return true;

	int inicio=1, fim=max;
	int meio, pt1, pt2;

	while(inicio <= fim){

		pt1 = inicio*inicio;
		pt2 = fim*fim;
		meio = pt1+pt2;
		
		if(meio == n)
			return true;

		if(meio < n)
			inicio++;
		else if(meio > n)
			fim--;
	}

	return false;
}


void ehSomaDQ2_PD(bool *todasSomas){

	int max = 71;	//sqrt(10000/2)

	for(int i=0; i<=max; i++){
		todasSomas[i*i] = true;
		for(int j=i; j<=max; j++)
			todasSomas[i*i + j*j] = true;
	}

}


int main(){
	

	int n;
	bool todasSomas[10002];
	
	memset(todasSomas, false, sizeof(todasSomas));
	ehSomaDQ2_PD(todasSomas);

	while(scanf("%d", &n) != EOF){
		if(n >= 0 and todasSomas[n])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}