/*
* Trabalho 3 - Sistemas Operacionais - 2014/01
* Implemente um mecanismo de tratamento de interrupções.
* 
* Marcos Vinicius Treviso (121150107) 
* {marcosvtreviso}@gmail.com
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
#include <iomanip>	// setw gantt diagram
#include <ctime>	// current time and date
#include <cstdlib>  // srand
#include <algorithm>// sorts
#include <vector>	// history, stateQueue, pair
#include <deque> 	// processQueue
#include <stack>	// programCounter
#include <unistd.h>	// sleep function
#include "rlutil/rlutil.h" // color
#include "InterruptHandler.cpp"	// interrupt class
#include "Process.cpp"	// process class
#include "Manager.cpp"  // manager class




int main(int argc, char const *argv[]){ 
	
	if(argc < 2){
		printf("Passe a quantidade de processos .\n");
		return 0;
	}

	srand(time(NULL));
	int i, qtd, type, priority, instruction;
	double tclock;

	qtd = atoi(argv[1]);
	tclock = (argc == 3) ? atof(argv[2]) : 0;
	rlutil::cls();
	
	Manager<Process> *manager = new Manager<Process>(tclock);
	manager->setAlgorithmType("ROUNDROBIN"); //FIFO/SJF/PRIORIDADE/ROUNDROBIN

	for(i=0; i<qtd; ++i){
		priority = (rand()%20)+1;
		type = rand()%2;
		instruction = (rand()%10)+1;
		manager->createProcess(priority, type, instruction);
	}
	
	manager->printLine();
	manager->printAction("INICIANDO SIMULACAO DO GERENCIAMENTO!");
	manager->printStates();
	manager->executeAllProcesses(1);

	manager->reportProcessesHistory();
	manager->reportGanttDiagram(true, true); //1.true = ordenado por id | 2.true = exibicao na mesma linha

	delete manager;


	return 0;
}