/*
* Trabalho 1A - Sistemas Operacionais - 2014/01
* Implementar um produtor-consumidor usando PThreads.
*
* Marcos Vinicius Treviso (121150107) 
* Wolgan Ens Quepfert (121151535)
* {marcosvtreviso, ens.wolgan}@gmail.com
*	
* Compile: g++ -o teste prodcons.cpp -Wall -Wextra -lpthread
* Run: ./teste <tempo.threads> <qtd.produtor> <qtd.consumidor>
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <unistd.h>   // sleep function
#include <sys/time.h> // crono function

using namespace std;

typedef unsigned long int uli;
typedef unsigned short int usi;


// estrutura para informacoes da thread
typedef struct _threadInfo{
	uli id; 					// codigo atomico da thread
	uli qtdProd, qtdCons;		// qtd de producoes/consumos
	usi tempo;					// tempo a cada intervalo de execucao
	usi caixasProd, caixasCons;	// caixas de producao/consumo individual
}threadInfo;


const int tempoExecucaoTotal = 5;	// tempo de execucao total em segundos
double timer; 						// timer para o cronometro
int itens; 							// qtd de itens produzidos
pthread_mutex_t mutex;				// thread mutex



// funcao para cronometrar o tempo de execucao
double crono(){
	struct timeval tv;
	gettimeofday(&tv, 0);
	return tv.tv_sec + tv.tv_usec / 1e6;
}


// funcao de producao
void *produzir(void *T){
	
	threadInfo *infos = (threadInfo *) T;

	while(1){

		if(crono()-timer > tempoExecucaoTotal)
			break;

		pthread_mutex_lock(&mutex);
		itens += infos->caixasProd; 
		pthread_mutex_unlock(&mutex);

		infos->qtdProd++;
		
		printf("\n\033[0;32m Caixa armazenada: Passaram a ser %d caixas \033[0m", itens); 

		sleep(infos->tempo); 
	}

	return 0;
} 


// funcao de consumo
void *consumir(void *T){

	threadInfo *infos = (threadInfo *) T;
	bool consumiu;

	while(1){

		if(crono()-timer > tempoExecucaoTotal)
			break;

		consumiu = false;

		pthread_mutex_lock(&mutex);
		if(itens >= infos->caixasCons){
			
			itens -= infos->caixasCons; 
			infos->qtdCons++;
			consumiu = true;

			printf("\n\033[0;31m Caixa retirada: Sobram %d caixas\033[0m", itens); 
		}
		pthread_mutex_unlock(&mutex);

		if(consumiu)
			sleep(infos->tempo);
	} 

	return 0;
} 




int main(int argc, char const *argv[]){ 
	
	if(argc < 4){
		printf("Passe o tempo de execucao da thread, a quantidade de produtores e consumidores.\n");
		return 0;
	}


	srand(time(NULL));
	uli i, qtdProd, qtdCons, total;
	usi tempo, caixasProd, caixasCons;

	tempo = atoi(argv[1]);	 	// tempo a cada intervalo de execucao
	qtdProd = atoi(argv[2]); 	// quantidade de produtores
	qtdCons = atoi(argv[3]); 	// quantidade de consumidores

	if(qtdProd<=3 || qtdCons<=3 || qtdProd>=10 || qtdCons>=10){
		printf("Intervalo aberto de produtores e consumidores de 3 a 10.\n");
		return 0;
	}


	total = qtdProd+qtdCons;	// total de threads
	caixasProd = (rand()%5)+1;	// producao individual [1,5]
	caixasCons = (rand()%5)+1;	// consumo individual [1,5]
	


	printf("\033[0;34m[       Produtor-Consumidor        ]\n");
	printf("====================================\n");
	printf("%lu Produtores | %lu Consumidores\n", qtdProd, qtdCons);
	printf("%hu Caixas produzidas por vez\n", caixasProd);
	printf("%hu Caixas consumidas por vez\n", caixasCons);
	printf("Producao e consumo a cada %hus\n", tempo);
	printf("====================================\n\n");


	// alocar memoria para vetor de thread e respectivas infos
	pthread_t *tid = new pthread_t[total];
	threadInfo *infos = new threadInfo[total];

	// preenchimento da estrutura de informacao das threads
	for(i=0; i<total; i++){
		infos[i].id = i;
		infos[i].qtdProd = infos[i].qtdCons = 0;
		infos[i].tempo = tempo;
		infos[i].caixasProd = caixasProd;
		infos[i].caixasCons = caixasCons;
	}


	// inicia cronometro, itens e o mutex
	timer = crono();
	itens = 0;
	pthread_mutex_init(&mutex, NULL);


	// cria as threads de producao
	for(i=0; i<qtdProd; i++)
		pthread_create(&tid[i], NULL, produzir, (void*)&infos[i]);

	// cria as threads de consumo
	for(i=qtdProd; i<total; i++)
		pthread_create(&tid[i], NULL, consumir, (void*)&infos[i]);

	// sincroniza as threads
	for(i=0; i<total; i++)
		pthread_join(tid[i], NULL);


	
	printf("\n-----------------------------------------\n");	
	printf("\033[0;34m");

	// imprime as informacoes das threads apos terminal o tempo total de execucao
	for(i=0; i<total; i++){
		printf("\nThread ID: %lu\n", infos[i].id);
		printf("Produziu: %lu | Consumiu: %lu\n", infos[i].qtdProd, infos[i].qtdCons);
	}

	printf("\nQuantidade final de itens: %d\n", itens);
	printf("\033[0m");
	

	// libera memoria
	delete[] tid;
	delete[] infos;

	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);

	return 0;
}