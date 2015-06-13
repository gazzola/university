/* 
Trabalho 2 - Implementação de Relógios Vetoriais. 
--- 
Para resolver a causalidade em sistemas distribuídos, pode se utilizar
relógios vetoriais.

Um relógio vetorial VC(a) designado a um evento a tem a seguinte propriedade:
se VC(a) < VC(b) para algum evento b, sabe-se que o evento a precede por
causalidade o evento b.

Pesquise mais sobre o assunto e faça um protótipo mostrando como o mesmo pode
ser implementado.

Sugestão 1: implemente usando threads, simulando o funcionamento de um sistema
distribuído. Cada thread pode sortear um tempo de espera e "enviar" uma
mensagem, uma unidade, a uma das demais threads.

Sugestão 2: Usar Processos e comunicar-se com RMI.

---

Marcos Vinicius Treviso
121150107

---

Compile: gcc -o trab -fopenmp
Execute: ./trab 

*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <omp.h>

// number of 'different processes'
#define N 5


typedef struct _proc{
	int from;	  // which process sent a message to this process
	int clock[N]; // vector clock of each process
}proc;



int max(int a, int b){
	if(a > b)
		return a;
	return b;
}


int createEvent(){
	return rand()%N;
}


void printClocks(proc *ps){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%d ", ps[i].clock[j]);
		printf("\n");
	}
	printf("\n");
}



int main(){

	proc ps[N];
	int i, from, to, actual;
	
	for(i=0; i<N; i++){
		memset(ps[i].clock, 0, sizeof(ps[i].clock));
		ps[i].from = -1;
	}
	
	while(1){
		#pragma omp parallel private(actual, to, i, from)
		{
			actual = omp_get_thread_num() % N;
			ps[actual].clock[actual]++;

			to = createEvent();
			ps[to].from = actual;

			// quando envia:
			for(i=0; i<N; i++)
				ps[i].from = actual;


			// quando recebe:
			#pragma critical
			{
				from = ps[actual].from;
				if(from >= 0 && from != actual){
					for(i=0; i<N; i++)
						ps[actual].clock[i] = max(ps[actual].clock[i], ps[from].clock[i]);
					ps[actual].clock[actual]++;
					ps[actual].from = -1;
				}
			}
		}

		printClocks(ps);
		// sleep(0.5);
	}

	return 0;
}