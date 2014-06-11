/*
* Trabalho 1B - Sistemas Operacionais - 2014/01
* Implemente uma representação de processo (ponto de vista do SO)
* 
* Marcos Vinicius Treviso (121150107) 
* Wolgan Ens Quepfert (121151535)
* {marcosvtreviso, ens.wolgan}@gmail.com
*	
* Compile: g++ -o teste ProcessRep.cpp -Wall -Wextra
* Run: ./teste <qtd.process> [tempo.clock]
* 
* se [tempo.clock] nao for passado, o intervalo de cada execucao
* sera determinado atraves da tecla `ENTER`.
*/


using namespace std;

					// bibs usadas para:
#include <iostream> // stream
#include <ctime>	// current time and date
#include <cstdlib>  // srand
#include <algorithm>// sort
#include <vector>	// history, stateQueue
#include <deque> 	// processQueue
#include <stack>	// programCounter
#include <unistd.h>	// sleep function
#include "rlutil/rlutil.h" // color
#include "Process.cpp"	// process class
#include "Manager.cpp"  // manager class




int main(int argc, char const *argv[]){ 
	
	if(argc < 2){
		printf("Passe a quantidade de processos .\n");
		return 0;
	}

	srand(time(NULL));
	int i, qtd, type, priority;
	double tclock;

	qtd = atoi(argv[1]);
	tclock = (argc == 3) ? atof(argv[2]) : 0;
	rlutil::cls();
	
	Manager<Process> *manager = new Manager<Process>(tclock);
	manager->setAlgorithmType("SJF");

	for(i=0; i<qtd; ++i){
		priority = (rand()%20)+1;
		type = rand()%2;
		manager->createProcess(priority, type);
	}
	
	manager->printLine();
	manager->printAction("PREPARAR PARA DECOLAGEM .......... DECOLAR!");
	manager->printStates();
	manager->executeAllProcesses(1000);


	manager->createProcess(1, 0);
	manager->createProcess(2, 1);
	manager->createProcess(3, 0);
	manager->createProcess(4, 1);
	manager->createProcess(5, 0);
	manager->executeAllProcesses(1000);

	manager->reportProcessesHistory();

	delete manager;


	return 0;
}