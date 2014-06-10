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
*/


#include <iostream> // stream
#include <ctime>	// current time and date
#include <cstdlib>  // srand
#include <vector>	// history, stateQueue
#include <deque> 	// processQueue
#include <stack>	// programCounter
#include <unistd.h>	// sleep function
#include "rlutil/rlutil.h" // color

using namespace std;



#define CRIADO 0
#define PRONTO 1
#define PRONTOSUS 2
#define BLOQUEADO 3
#define BLOQUEADOSUS 4
#define EXECUTANDO 5
#define ENCERRADO 6
#define MAX_PRONTO 4
#define MAX_BLOQUEADO 4


typedef unsigned long int uli;
typedef unsigned short int usi;


class Process{

	private:
		uli id;
		usi priority;
		usi state;
		usi type; // cpu/io bound
		vector<string> history;
		int instIterations;	// no nosso trabalho, a instrucao eh a qtd de
		int runIterations;	// iteracoes que um processo pode executar
		time_t rawtime;
		struct tm *timeinfo;
		
		void deleteHistory();

	public:

		Process(){}
		Process(uli id, usi priority, usi state, usi type);
		virtual ~Process();
		uli getId();
		usi getPriority();
		usi getState();
		usi getType();
		int getInstIterations();
		vector<string> getHistory();
		void setPriority(usi priority);
		void setState(usi state);
		void addHistory(string str);
		void setInstIterations(int instIterations);
		void execute(int moreIterations);
		bool alreadyExecuted();

};


Process::Process(uli id, usi priority, usi state, usi type){
	this->id = id;
	this->setPriority(priority);
	this->setState(state);
	this->addHistory("inicio");
	this->type = type;
	this->setInstIterations(0);
	this->runIterations = 0;
}

Process::~Process(){
	deleteHistory();
}


void Process::deleteHistory(){
	vector<string> temp;
	this->history.swap(temp);
}


uli Process::getId(){
	return this->id;
}

usi Process::getPriority(){
	return this->priority;
}

usi Process::getState(){
	return this->state;
}

usi Process::getType(){
	return this->type;
}

int Process::getInstIterations(){
	return this->instIterations;
}

vector<string> Process::getHistory(){
	return this->history;
}


void Process::setPriority(usi priority){
	this->priority = priority;
}

void Process::setState(usi state){
	this->state = state;
}

void Process::setInstIterations(int instIterations){
	this->instIterations = instIterations;
}


void Process::addHistory(string msg){
	time(&this->rawtime);
	this->timeinfo = localtime(&this->rawtime);
	char buffer[80];
	
	strftime(buffer, sizeof(buffer), "%Y-%m-%d.%X", this->timeinfo);
	string history = string(buffer) + string(" -> ") + msg;
	this->history.push_back(history);
}

void Process::execute(int moreIterations){
	this->runIterations += moreIterations;
}

bool Process::alreadyExecuted(){
	return (this->runIterations >= this->instIterations);
}




template <class T>
class Manager{

	private:
		uli qtdProcess; 				// qtd de processos alocados
		uli idProcesses;
		vector< deque<T> > stateQueue; 	// lista com tds os estados
		stack<uli> programCounter;		// instrucoes a serem executadas
		T *runningProcces;				// processo em execucao
		double tclock;

		bool switchState(int origin, int final, uli idProcess);
		void printState(deque<T> &state);
		bool interruption();
		bool block();
		bool hasSpace(int state);
		string catchState(int state);
		void escalonar(int state, string typeAlgorithm);

	public:
		Manager(double tclock);
		virtual ~Manager();
		void createProcess(usi priority, usi type);
		void executeProcess(int iterations);
		void executeAllProcesses(int iterations);
		void lockProcess(uli idProcess);
		bool unlockAllProcesses();
		bool unlockProcess();
		bool closeProcess(int origin, uli idProcess);
		void printStates();
		void printLine();
		void printAction(string action);
		void reportProcessesHistory();

};


template <class T>
Manager<T>::Manager(double tclock){
	this->qtdProcess = this->idProcesses = 0;
	this->runningProcces = NULL;
	this->tclock = tclock;

	for(int i=CRIADO; i<=ENCERRADO; i++)
		this->stateQueue.push_back(deque<Process>());
}

template <class T>
Manager<T>::~Manager(){

	for(int i=CRIADO; i<ENCERRADO; i++)
		while(this->stateQueue[i].size() > 0)
			this->stateQueue[i].pop_front(); // c++ chama automaticamente o destrutor dos processos

	vector< deque<T> > temp;
	this->stateQueue.swap(temp);
}


template <class T>
bool Manager<T>::switchState(int origin, int final, uli idProcess){

	deque<Process>::iterator it;
	string str;

	for(it=this->stateQueue[origin].begin(); it!=this->stateQueue[origin].end(); ++it){
		if(it->getId() == idProcess){
			str = "movido de " + this->catchState(origin) + " para " + this->catchState(final);
			it->addHistory(str);
			this->stateQueue[final].push_back(*it);
			this->stateQueue[origin].erase(it);

			//if(final == PRONTO || final == BLOQUEADO || final == PRONTOSUS || final == BLOQUEADOSUS)
			//escalonar(final, FIFO/SJF/PRIORIDADES - ROUND_ROBIN)
			//verificar como vamos fazer a preempcao atraves da diminuicao da prioridade

			return true;
		}
	}

	return false;
}

template <class T>
string Manager<T>::catchState(int state){
	string str = "SEM_ESTADO";
	switch(state){
		case CRIADO:
			str = "CRIADO";
			break;
		case PRONTO:
			str = "PRONTO";
			break;
		case PRONTOSUS:
			str = "PRONTO/SUSPENSO";
			break;
		case EXECUTANDO:
			str = "EXECUTANDO";
			break;
		case BLOQUEADO:
			str = "BLOQUEADO";
			break;
		case BLOQUEADOSUS:
			str = "BLOQUEADO/SUSPENSO";
			break;
		case ENCERRADO:
			str = "ENCERRADO";
			break;
	}

	return str;
}


template <class T>
bool Manager<T>::interruption(){
	return (rand()%250 == 42);
}

template <class T>
bool Manager<T>::block(){
	return (rand()%250 == 4);
}

template <class T>
bool Manager<T>::hasSpace(int state){
	if(state == PRONTO)
		return (this->stateQueue[PRONTO].size() < MAX_PRONTO);
	else
		return (this->stateQueue[BLOQUEADO].size() < MAX_BLOQUEADO);
}


template <class T>
void Manager<T>::createProcess(usi priority, usi type){

	if(priority < 1 || priority > 20){
		cout << "Prioridade do processo no intervalo [1,20]";
		return;
	}
	

	Manager::qtdProcess++;
	Manager::idProcesses++;


	uli id = Manager::idProcesses;
	
	Process *p = new Process(id, priority, CRIADO, type);
	p->setInstIterations((rand()%99000)+1000);
	this->stateQueue[CRIADO].push_back(*p);

	this->printLine();
	this->printAction("CRIADO");
	this->printStates();
	
	if(this->hasSpace(PRONTO)){
		if(this->switchState(CRIADO, PRONTO, id)){

			this->printLine();
			this->printAction("CRIADO -> PRONTO");
			this->printStates();

			if(this->interruption()){
				this->closeProcess(PRONTO, id);
				this->printLine();
				this->printAction("PRONTO -> ENCERRADO");
				this->printStates();
			}
		}
	}
	else{
		if(this->switchState(CRIADO, PRONTOSUS, id)){
			this->printLine();
			this->printAction("CRIADO -> PRONTO/SUSPENSO");
			this->printStates();
		}
	}
}


template <class T>
void Manager<T>::executeProcess(int iterations){
	
	Process p = this->stateQueue[PRONTO].front();
	this->switchState(PRONTO, EXECUTANDO, p.getId());

	this->printLine();
	this->printAction("PRONTO -> EXECUTANDO");
	this->printStates();

	while(!p.alreadyExecuted()){
		if(this->block()){

			if(this->hasSpace(BLOQUEADO)){
				this->lockProcess(p.getId());
				this->printLine();
				this->printAction("EXECUTANDO -> BLOQUEADO");
				this->printStates();
			}
			else{
				if(this->switchState(EXECUTANDO, BLOQUEADOSUS, p.getId())){
					this->printLine();
					this->printAction("EXECUTANDO -> BLOQUEADO/SUSPENSO");
					this->printStates();
				}
			}


			if(this->stateQueue[PRONTOSUS].size() > 0){
				Process pr = this->stateQueue[PRONTOSUS].front();
				this->switchState(PRONTOSUS, PRONTO, pr.getId());

				this->printLine();
				this->printAction("PRONTO/SUSPENSO -> PRONTO");
				this->printStates();
			}

			if(this->stateQueue[PRONTO].size() > 0){
				p = this->stateQueue[PRONTO].front();
				this->switchState(PRONTO, EXECUTANDO, p.getId());
				this->printLine();
				this->printAction("PRONTO -> EXECUTANDO");
				this->printStates();
			}
			else
				break;
		}
		else if(this->interruption()){
			switchState(EXECUTANDO, PRONTO, p.getId());
			this->printLine();
			this->printAction("EXECUTANDO -> PRONTO");
			this->printStates();
			break;
		}
		else{
			p.execute(iterations);
		}
	}

	
	if(this->closeProcess(EXECUTANDO, p.getId())){
		Manager::qtdProcess--;
		this->printLine();
		this->printAction("EXECUTANDO -> ENCERRADO");
		this->printStates();

		if(this->stateQueue[PRONTOSUS].size() > 0){
			Process pr = this->stateQueue[PRONTOSUS].front();
			this->switchState(PRONTOSUS, PRONTO, pr.getId());

			this->printLine();
			this->printAction("PRONTO/SUSPENSO -> PRONTO");
			this->printStates();
		}

	}
	
	this->unlockProcess();

}

template <class T>
void Manager<T>::executeAllProcesses(int iterations){
	while(this->stateQueue[PRONTO].size() > 0)
		this->executeProcess(iterations);
}



template <class T>
void Manager<T>::lockProcess(uli idProcess){
	this->switchState(EXECUTANDO, BLOQUEADO, idProcess);
}


template <class T>
bool Manager<T>::unlockProcess(){

	bool ok = false;

	if(this->interruption()){
		Process p = this->stateQueue[BLOQUEADO].front();
		this->closeProcess(BLOQUEADO, p.getId());
		this->printLine();
		this->printAction("BLOQUEADO -> ENCERRADO");
		this->printStates();

		ok = true;
	}
	else{

		if(this->hasSpace(PRONTO)){
			if(this->stateQueue[BLOQUEADO].size() > 0){

				Process p = this->stateQueue[BLOQUEADO].front();
				this->switchState(BLOQUEADO, PRONTO, p.getId());

				this->printLine();
				this->printAction("BLOQUEADO -> PRONTO");
				this->printStates();

				ok = true;
			}
			else{
				if(this->stateQueue[BLOQUEADOSUS].size() > 0){

					Process p = this->stateQueue[BLOQUEADOSUS].front();
					this->switchState(BLOQUEADOSUS, PRONTO, p.getId());

					this->printLine();
					this->printAction("BLOQUEADO/SUSPENSO -> PRONTO");
					this->printStates();

					ok = true;
				}
			}
		}
		else{
			if(this->stateQueue[BLOQUEADO].size() > 0){

				Process p = this->stateQueue[BLOQUEADO].front();
				this->switchState(BLOQUEADO, PRONTOSUS, p.getId());

				this->printLine();
				this->printAction("BLOQUEADO -> PRONTO/SUSPENSO");
				this->printStates();

				ok = true;
			}
			else{
				if(this->stateQueue[BLOQUEADOSUS].size() > 0){

					Process p = this->stateQueue[BLOQUEADOSUS].front();
					this->switchState(BLOQUEADOSUS, PRONTOSUS, p.getId());

					this->printLine();
					this->printAction("BLOQUEADO/SUSPENSO -> PRONTO/SUSPENSO");
					this->printStates();

					ok = true;
				}
			}
		}
	}

	return ok;
}


template <class T>
bool Manager<T>::unlockAllProcesses(){

	bool ok = false;
	while(true){
		if(this->unlockProcess())
			ok = true;
		else
			break;
	}

	return ok;
}



template <class T>
bool Manager<T>::closeProcess(int origin, uli idProcess){
	if(this->switchState(origin, ENCERRADO, idProcess)){
		Manager::qtdProcess--;
		return true;
	}

	// como quero que apareca os processos na fila do encerrado
	// nao estou dando delete nos processos aqui, so no fim do programa

	return false;
}



template <class T>
void Manager<T>::reportProcessesHistory(){
	
	deque<Process>::iterator it;
	char buffer[128];
	vector<string> hist;
	string str;
	
	rlutil::cls();
	for(it=this->stateQueue[ENCERRADO].begin(); it!=this->stateQueue[ENCERRADO].end(); ++it){
		
		this->printLine();
		str = (it->getType() == 0) ? "CPU BOUND" : "I/O BOUND";
		sprintf(buffer, "ID:%lu  -  PRIORIDADE:%hu  -  ", it->getId(), it->getPriority());
		str = buffer + str;
		this->printAction("HISTORIA DO PROCESSO  =  " + str + ":");

		hist = it->getHistory();

		rlutil::setColor(7);
		for(int j=0; j<hist.size(); j++)
			cout << hist[j] << endl;

		cout << endl;
	}
}


template <class T>
void Manager<T>::printLine(){
	rlutil::setColor(15);
	cout << "--------------------------------" << endl;
}

template <class T>
void Manager<T>::printAction(string action){
	rlutil::setColor(15);
	cout << endl << action << endl;
}

template <class T>
void Manager<T>::printState(deque<T> &state){
	deque<Process>::iterator it;
	for(it=state.begin(); it!=state.end(); it++)
		cout << it->getId() << " ";
}



template <class T>
void Manager<T>::printStates(){
	
	cout << endl;

	rlutil::setColor(1);
	cout << "CRIADO: ";
	this->printState(this->stateQueue[CRIADO]);
	cout << endl << endl;

	rlutil::setColor(2);
	cout << "PRONTO: ";
	this->printState(this->stateQueue[PRONTO]);
	cout << endl << endl;

	rlutil::setColor(10);
	cout << "PRONTO/SUS: ";
	this->printState(this->stateQueue[PRONTOSUS]);
	cout << endl << endl;

	rlutil::setColor(4);
	cout << "BLOQUEADO: ";
	this->printState(this->stateQueue[BLOQUEADO]);
	cout << endl << endl;

	rlutil::setColor(12);
	cout << "BLOQUEADO/SUS: ";
	this->printState(this->stateQueue[BLOQUEADOSUS]);
	cout << endl << endl;

	rlutil::setColor(6);
	cout << "EXECUTANDO: ";
	this->printState(this->stateQueue[EXECUTANDO]);
	cout << endl << endl;

	rlutil::setColor(3);
	cout << "ENCERRADO: ";
	this->printState(this->stateQueue[ENCERRADO]);
	cout << endl << endl;


	if(this->tclock == 0)
		getchar();
	else
		sleep(this->tclock);
	rlutil::cls();
	rlutil::setColor(7);

}






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

	for(i=0; i<qtd; ++i){
		priority = (rand()%20)+1;
		type = rand()%2;
		manager->createProcess(priority, type);
	}
	
	manager->printLine();
	manager->printAction("PREPARAR PARA DECOLAGEM .......... DECOLAR!");
	manager->printStates();
	manager->executeAllProcesses(1000);

	manager->reportProcessesHistory();

	delete manager;


	return 0;
}