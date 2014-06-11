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
#include <algorithm>// sort
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
#define CPUBOUND 0
#define IOBOUND 1


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
		uli getId() const;
		usi getPriority() const;
		usi getState();
		usi getType();
		int getInstIterations() const;
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


uli Process::getId() const{
	return this->id;
}

usi Process::getPriority() const{
	return this->priority;
}

usi Process::getState(){
	return this->state;
}

usi Process::getType(){
	return this->type;
}

int Process::getInstIterations() const{
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
	if(this->type == CPUBOUND) //se for cpu bound
		this->runIterations += moreIterations;
	else //se for i/o bound (demora mais, e a chance de ter uma interrupcao ou um bloqueio eh maior)
		this->runIterations += moreIterations/2;
}

bool Process::alreadyExecuted(){
	return (this->runIterations >= this->instIterations);
}





bool orderByFIFO(const Process &i, const Process &j){
	return (i.getId() < j.getId());
}

bool orderBySJF(const Process &i, const Process &j){
	return (i.getInstIterations() < j.getInstIterations());
}

bool orderByPriority(const Process &i, const Process &j){
	return (i.getPriority() > j.getPriority());
}


template <class T>
class Manager{

	private:
		uli qtdProcess; 						// qtd de processos alocados
		uli idProcesses;
		vector< deque<Process> > stateQueue; 	// lista com tds os estados
		stack<uli> programCounter;				// instrucoes a serem executadas
		Process *runningProcces;				// processo em execucao
		string algorithmType;
		double tclock;

		bool switchState(int origin, int final, uli idProcess);
		void printState(deque<T> &state);
		bool interruption();
		bool block();
		bool preEmption();
		bool hasSpace(int state);
		string catchStateName(int state);
		void escalonar(int state);
		void decrementPriority();
		void incrementPriority();


	public:
		Manager(double tclock);
		virtual ~Manager();
		void setAlgorithmType(string alg);
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
	this->algorithmType = "FIFO";
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
void Manager<T>::setAlgorithmType(string alg){
	if(alg == "FIFO" || alg == "SJF" || alg == "PRIORIDADE" || alg == "ROUNDROBIN")
		this->algorithmType = alg;
	else{

		cout << "Escolhar um tipo de algoritmo valido";
		return;
	}

}


template <class T>
void Manager<T>::escalonar(int state){

	if(this->algorithmType == "SJF")
		sort(this->stateQueue[state].begin(), this->stateQueue[state].end(), orderBySJF);
	else if(this->algorithmType == "PRIORIDADE")
		sort(this->stateQueue[state].begin(), this->stateQueue[state].end(), orderByPriority);
	else if(this->algorithmType == "ROUNDROBIN")
		sort(this->stateQueue[state].begin(), this->stateQueue[state].end(), orderBySJF);
	
	//	nao preicsa ordenar no FIFO, pois ja esta inserindo no final do deque
	//	mantento assim a razao de o primeiro a entrar eh o primeiro a sair.
}


template <class T>
void Manager<T>::decrementPriority(){
	if(this->algorithmType == "SJF" || this->algorithmType == "ROUNDROBIN"){
		int inst = this->stateQueue[EXECUTANDO].front().getInstIterations();
		if(inst > 1001)
			this->stateQueue[EXECUTANDO].front().setInstIterations(inst-1000);
	}
	else{
		int priority = this->stateQueue[EXECUTANDO].front().getPriority();
		if(priority > 1)
			this->stateQueue[EXECUTANDO].front().setPriority(priority-1);
	}
}


template <class T>
void Manager<T>::incrementPriority(){
	if(this->algorithmType == "SJF" || this->algorithmType == "ROUNDROBIN"){
		int inst = this->stateQueue[EXECUTANDO].front().getInstIterations();
		this->stateQueue[EXECUTANDO].front().setInstIterations(inst+1000);
	}
	else{ //FIFO 
		int priority = this->stateQueue[EXECUTANDO].front().getPriority();
		if(priority < 20)
			this->stateQueue[EXECUTANDO].front().setPriority(priority+1);
	}
}




template <class T>
bool Manager<T>::switchState(int origin, int final, uli idProcess){

	deque<Process>::iterator it;
	string str;

	for(it=this->stateQueue[origin].begin(); it!=this->stateQueue[origin].end(); ++it){
		if(it->getId() == idProcess){
			
			str = "movido de " + this->catchStateName(origin) + " para " + this->catchStateName(final);
			it->addHistory(str);
			
			this->stateQueue[final].push_back(*it);
			this->stateQueue[origin].erase(it);

			// maior desempenho fazendo uma busca binaria para buscar a posicao a ser inserido o processo O(log n)
			// ou pode-se percorrer normalmente e gastar O(n)
			// o metodo usado aqui gasta O(nlog n), pois usa a funcao qsort para reordenar os processos
			if(final == PRONTO || final == BLOQUEADO || final == PRONTOSUS || final == BLOQUEADOSUS)
				escalonar(final);
			

			this->printLine();
			this->printAction(this->catchStateName(origin)+" -> "+this->catchStateName(final));
			this->printStates();

			return true;
		}
	}

	return false;
}

template <class T>
string Manager<T>::catchStateName(int state){
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
	return (rand()%250 == 6);
}

template <class T>
bool Manager<T>::preEmption(){
	return (rand()%2 == 1);
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
			if(this->interruption())
				this->closeProcess(PRONTO, id);
		}
	}
	else
		this->switchState(CRIADO, PRONTOSUS, id);
}




template <class T>
void Manager<T>::executeProcess(int iterations){
	
	Process p = this->stateQueue[PRONTO].front();
	this->switchState(PRONTO, EXECUTANDO, p.getId());

	while(!p.alreadyExecuted()){
		if(this->block()){

			if(this->hasSpace(BLOQUEADO))
				this->lockProcess(p.getId());
			else
				this->switchState(EXECUTANDO, BLOQUEADOSUS, p.getId());


			if(this->stateQueue[PRONTOSUS].size() > 0)
				this->switchState(PRONTOSUS, PRONTO, this->stateQueue[PRONTOSUS].front().getId());


			if(this->stateQueue[PRONTO].size() > 0){
				p = this->stateQueue[PRONTO].front();
				this->runningProcces = &p;
				this->switchState(PRONTO, EXECUTANDO, p.getId());
			}
			else
				break;
		}
		else if(this->interruption()){

			this->runningProcces = &p;

			if(this->preEmption())
				this->decrementPriority();
			else
				this->incrementPriority();

			switchState(EXECUTANDO, PRONTO, p.getId());
			break;
		}
		else{
			p.execute(iterations);
			this->runningProcces = &p;
		}
	}

	
	if(this->closeProcess(EXECUTANDO, p.getId()))
		if(this->stateQueue[PRONTOSUS].size() > 0 && this->hasSpace(PRONTO))
			this->switchState(PRONTOSUS, PRONTO, this->stateQueue[PRONTOSUS].front().getId());
	
	this->unlockAllProcesses(); // se quiser desbloquear todos processos para a fila de prontos ou pronto/susp
	//this->unlockProcess();
}



template <class T>
void Manager<T>::executeAllProcesses(int iterations){
	while(this->stateQueue[PRONTO].size() > 0 || this->stateQueue[BLOQUEADO].size() > 0)
		this->executeProcess(iterations);
}


template <class T>
void Manager<T>::lockProcess(uli idProcess){
	this->switchState(EXECUTANDO, BLOQUEADO, idProcess);
	// aqui seria possivel ja verificar se ao inves de ir para bloqueado
	// o processo poderia ir para o final da fila de prontos
}


template <class T>
bool Manager<T>::unlockProcess(){

	bool ok = false;

	if(this->interruption()){
		this->closeProcess(BLOQUEADO, this->stateQueue[BLOQUEADO].front().getId());
		ok = true;
	}
	else{
		if(this->hasSpace(PRONTO)){
			if(this->stateQueue[BLOQUEADO].size() > 0){
				this->switchState(BLOQUEADO, PRONTO, this->stateQueue[BLOQUEADO].front().getId());
				ok = true;
			}
			else if(this->stateQueue[BLOQUEADOSUS].size() > 0){
				this->switchState(BLOQUEADOSUS, PRONTO, this->stateQueue[BLOQUEADOSUS].front().getId());
				ok = true;
			}
		}
		else{
			if(this->stateQueue[BLOQUEADO].size() > 0){
				this->switchState(BLOQUEADO, PRONTOSUS, this->stateQueue[BLOQUEADO].front().getId());
				ok = true;
			}
			else if(this->stateQueue[BLOQUEADOSUS].size() > 0){
				this->switchState(BLOQUEADOSUS, PRONTOSUS, this->stateQueue[BLOQUEADOSUS].front().getId());
				ok = true;
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
		for(usi j=0; j<hist.size(); j++)
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
		cout << it->getId() << "[" << it->getPriority() << "," << it->getInstIterations()/1000 << "] ";
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