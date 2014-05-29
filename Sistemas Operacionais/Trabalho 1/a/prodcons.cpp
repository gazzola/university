/*
* Trabalho 1 - A - Sistemas Operacionais - 2014/01
* Implementar um produtor-consumidor usando PThreads. 
*
* Marcos Vinicius Treviso (121150107) 
* marcosvtreviso@gmail.com
*	
* Compile: g++ -o teste prodcons.cpp -Wall -Wextra -lpthread
* Run: ./teste <tempo.threads> <qtd.produtor> <qtd.consumidor>
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <unistd.h>


int itens = 0; 
pthread_mutex_t mutex;

void *colocar(void *T){
	
	int tempo = *((int*)T);

	while(1){
		pthread_mutex_lock(&mutex);
		itens++; 
		pthread_mutex_unlock(&mutex);

		printf("\n Caixa armazenada: Passaram a ser %d caixas", itens); 
		sleep(tempo); 
	}

	return 0;
} 

void *retirar(void *T){

	int tempo = *((int*)T);

	while(1){
		pthread_mutex_lock(&mutex);
		itens--; 
		pthread_mutex_unlock(&mutex);

		printf("\n Caixa retirada: Sobram %d caixas", itens); 
		sleep(tempo); 
	} 

	return 0;
} 


int main(int argc, char const *argv[]){ 
	
	if(argc < 4){
		printf("Passe o tempo de execucao da thread, a quantidade de produtores e consumidores.\n");
		return 0;
	}

	int tempoT = atoi(argv[1]);
	int qtdprod = atoi(argv[2]);
	int qtdcons = atoi(argv[3]);
	int total = qtdprod+qtdcons;

	pthread_t *tid = (pthread_t *) malloc (total * sizeof(pthread_t));
	pthread_mutex_init(&mutex, NULL);

	for(int i=0; i<qtdprod; i++)
		pthread_create(&tid[i], NULL, colocar, (void*)&tempoT);

	for(int i=qtdprod; i<total; i++)
		pthread_create(&tid[i], NULL, retirar, (void*)&tempoT);

	for(int i=0; i<total; i++)
		pthread_join(tid[i], NULL);

	
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);

	return 0;
}
