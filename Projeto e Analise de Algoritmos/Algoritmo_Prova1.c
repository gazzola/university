#include <stdio.h>
#include <stdlib.h>

#define NLC 5


void preencheMatrizNormal(int m[NLC][NLC]){
	int i, j;
	for(i=0; i<NLC; i++)
		for(j=0; j<NLC; j++)
			m[i][j] = (i>=j) ? 1 : 0;
}

void preencheMatrizReversa(int m[NLC][NLC]){
	int i, j;
	for(i=0; i<NLC; i++)
		for(j=0; j<NLC; j++)
			m[i][j] = (i+j < NLC) ? 1 : 0;
}


int contarNormal(int m[NLC][NLC]){

	int i, t, last;
	t = last = 0;

	for(i=0; i<NLC; i++){
		if(m[i][i]){
			t += (i+1);
			last = (i+1);
		}
		else
			t += last;
	}

	return t;
}


int contarReversa(int m[NLC][NLC]){

	int i, t, last, count;
	t = last = count = 0;

	for(i=(NLC-1); i>=0; i--){
		if(m[i][count]){
			t += (count+1);
			last = (count+1);
		}
		else
			t += last;
		count++;
	}

	return t;

}


void imprime(int m[NLC][NLC]){
	int i,j;
	for(i=0; i<NLC; i++){
		for(j=0; j<NLC; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}



int main(int argc, char const *argv[]){	

	int val;
	
	int mm[NLC][NLC];
	preencheMatrizNormal(mm);
	printf("\nMATRIZ NORMAL:\n");
	imprime(mm);
	val = contarNormal(mm);
	printf("\nTOTAL: %d\n\n", val);

	//-----------------------------//

	int mr[NLC][NLC];
	preencheMatrizReversa(mr);
	printf("\nMATRIZ REVERSA:\n");
	imprime(mr);
	val = contarReversa(mr);
	printf("\nTOTAL: %d\n\n", val);

	
	return 0;
}