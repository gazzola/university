/*
* Trabalho 1 - A - Sistemas Operacionais - 2014/01
* Implementar um produtor-consumidor usando PThreads. 
*
* Marcos Vinicius Treviso (121150107) 
* marcosvtreviso@gmail.com
*	
* Compile: g++ -o teste ProdutorConsumidor.cpp -Wall -Wextra -lpthread
* Run: ./teste <tempo.threads> <qtd.produtor> <qtd.consumidor>
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <unistd.h>

using namespace std;



//ProdutoConsumidorNamesapce
namespace pcn{

	class Fabrica{

		protected:
			static pthread_mutex_t mutex;
			static pthread_t *tid;
			static int totalThreads, items;
			static bool produtorOk, consumidorOk;

		public:
			Fabrica(){
				items = 0;
				totalThreads = 0;
				produtorOk = consumidorOk = true;
			}

			void addThreads(int totalThreads){
				totalThreads += totalThreads;
			}

			void allocThreads(){
				tid = new pthread_t[this->totalThreads];
			}

			virtual ~Fabrica(){
				pthread_mutex_destroy(&mutex);
				pthread_exit(NULL);
				delete[] tid;
			}

			static void *helperPut(void *context){
				return ((Fabrica *)context)->put((void*)1);
			}

			static void *put(void *T){

				int tx = *((int*)T);

				if(produtorOk){
					while(true){
						pthread_mutex_lock(&mutex);
						items++; 
						pthread_mutex_unlock(&mutex);
						printf("\n Caixa armazenada: Passaram a ser %d caixas", items); 
						sleep(tx); 
					}
				}

				return 0;
			}

			static void *remove(void *T){

				int tx = *((int*)T);

				if(consumidorOk){
					while(true){
						pthread_mutex_lock(&mutex);
						items--; 
						pthread_mutex_unlock(&mutex);
						printf("\n Caixa retirada: Sobram %d caixas", items);  
						sleep(tx); 
					}
				}

				return 0;
			}

	};


	class Produtor: public Fabrica{

		private:
			static int itemsProdutor;
			static int ammountProdutor;
			static bool dead;

		public:
			
			Produtor(int ammountProdutor){
				this->ammountProdutor = ammountProdutor;
				this->itemsProdutor = 0;
				this->dead = false;
			}

			~Produtor(){
				produtorOk = false;
			}

			static int getItems(){
				return itemsProdutor;
			}

			static int getAmmount(){
				return ammountProdutor;
			}

			void createThreads(int tempo){
				for(int i=0; i<Produtor::getAmmount(); i++)
					pthread_create(&this->tid[i], NULL, &helperPut, (void*)this);//(void*)&tempo
			}

			void joinThreads(){
				for(int i=0; i<Produtor::getAmmount(); i++)
					pthread_join(this->tid[i], NULL);
			}
	};


};

using namespace pcn;



int main(int argc, char const *argv[]){ 
	
	if(argc < 4){
		printf("Passe o tempo de execucao da thread, a quantidade de produtores e consumidores.\n");
		return 0;
	}

	int tempoT = atoi(argv[1]);
	int qtdprod = atoi(argv[2]);
	int qtdcons = atoi(argv[3]);
	int total = qtdprod+qtdcons;

	Fabrica *fab = new Fabrica();


	return 0;
}
