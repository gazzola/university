#include "Manager.h"


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




bool orderById(const pair<uli, pair<int, int> > &i, const pair<uli, pair<int, int> > &j){
	return (i.first < j.first);
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
	//else if(this->algorithmType == "ROUNDROBIN")
	//	sort(this->stateQueue[state].begin(), this->stateQueue[state].end(), orderBySJF);
	
	//	nao preicsa ordenar no FIFO, pois ja esta inserindo no final do deque
	//	mantento assim a razao de o primeiro a entrar eh o primeiro a sair.
}


template <class T>
void Manager<T>::decrementPriority(){
	if(this->algorithmType == "SJF" || this->algorithmType == "ROUNDROBIN"){
		int inst = this->stateQueue[EXECUTANDO].front().getInstIterations();
		if(inst > 1001)
			this->stateQueue[EXECUTANDO].front().setInstIterations(inst-1);
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
		this->stateQueue[EXECUTANDO].front().setInstIterations(inst+1);
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
	return (rand()%150 == 42); 
}

template <class T>
bool Manager<T>::block(){
	return (rand()%150 == 6);
}

template <class T>
bool Manager<T>::preemption(){
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
void Manager<T>::createProcess(usi priority, usi type, int instruction){

	if(priority < 1 || priority > 20){
		cout << "Prioridade do processo no intervalo [1,20]";
		return;
	}
	

	Manager::qtdProcess++;
	Manager::idProcesses++;
	uli id = Manager::idProcesses;
	
	Process *p = new Process(id, priority, CRIADO, type);
	p->setInstIterations(instruction);
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
	
	//Process p = this->stateQueue[PRONTO].front();
	this->runningProcces = &this->stateQueue[PRONTO].front();
	this->switchState(PRONTO, EXECUTANDO, this->stateQueue[PRONTO].front().getId());
	int its = 0;

	while(!this->stateQueue[EXECUTANDO].front().alreadyExecuted()){

		if(this->block()){

			this->addDiagramProcess(this->stateQueue[EXECUTANDO].front().getId(), its, 0);

			if(this->hasSpace(BLOQUEADO))
				this->lockProcess(this->stateQueue[EXECUTANDO].front().getId());
			else
				this->switchState(EXECUTANDO, BLOQUEADOSUS, this->stateQueue[EXECUTANDO].front().getId());


			if(this->stateQueue[PRONTOSUS].size() > 0)
				this->switchState(PRONTOSUS, PRONTO, this->stateQueue[PRONTOSUS].front().getId());


			if(this->stateQueue[PRONTO].size() > 0){
				this->runningProcces = &this->stateQueue[PRONTO].front();
				this->switchState(PRONTO, EXECUTANDO, this->stateQueue[PRONTO].front().getId());
				its = 0;
			}
			else
				break;
		}
		else if(this->interruption()){

			this->addDiagramProcess(this->stateQueue[EXECUTANDO].front().getId(), its, 0);

			this->runningProcces = &this->stateQueue[EXECUTANDO].front();

			if(this->preemption())
				this->decrementPriority();
			else
				this->incrementPriority();

			switchState(EXECUTANDO, PRONTO, this->stateQueue[EXECUTANDO].front().getId());
			break;
		}
		else{
			this->stateQueue[EXECUTANDO].front().execute(iterations);
			this->runningProcces = &this->stateQueue[EXECUTANDO].front();
			its++;

			if(this->algorithmType == "ROUNDROBIN"){
				if(its == QUANTUM){
					
					if(this->stateQueue[EXECUTANDO].front().alreadyExecuted())
						break;

					this->addDiagramProcess(this->stateQueue[EXECUTANDO].front().getId(), its, 0);
					switchState(EXECUTANDO, PRONTO, this->stateQueue[EXECUTANDO].front().getId());
					its = 0;

					if(this->stateQueue[PRONTO].size() > 0)
						this->switchState(PRONTO, EXECUTANDO, this->stateQueue[PRONTO].front().getId());
					else
						break;
				}
			}
		}
	}

	
	if(this->closeProcess(EXECUTANDO, this->stateQueue[EXECUTANDO].front().getId())){
		this->addDiagramProcess(this->stateQueue[EXECUTANDO].front().getId(), its, 0);
		if(this->stateQueue[PRONTOSUS].size() > 0 && this->hasSpace(PRONTO))
			this->switchState(PRONTOSUS, PRONTO, this->stateQueue[PRONTOSUS].front().getId());
	}
	
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
void Manager<T>::addDiagramProcess(uli idProcesses, int runnedIterations, int position){
	this->ganttDiagram.push_back(make_pair(idProcesses, make_pair(runnedIterations, position)));
}

template <class T>
void Manager<T>::reportGanttDiagram(bool idOrder, bool idOrderInLine){
	
	rlutil::cls();
	this->printLine();
	this->printAction("DIAGRAMA DE GANTT (Processos/Duracao):");
	cout << endl;

	int i, j, last = 0;

	if(idOrder){
		
		for(i=0; i<this->ganttDiagram.size(); i++){
			this->ganttDiagram[i].second.second = last;
			for(j=0; j<this->ganttDiagram[i].second.first; j++);
			last += j;
		}

		sort(this->ganttDiagram.begin(), this->ganttDiagram.end(), orderById);

		if(idOrderInLine){

			bool *alreadyPass = new bool[Manager::idProcesses+1]();

			for(i=0; i<this->ganttDiagram.size(); i++){
				if(!alreadyPass[this->ganttDiagram[i].first]){
					rlutil::setColor(((this->ganttDiagram[i].first-1)%14)+1);

					cout << setw(3) << this->ganttDiagram[i].first << " :";
					cout << setw(3 + this->ganttDiagram[i].second.second);

					for(j=0; j<this->ganttDiagram[i].second.first; j++)
						cout << "|";
					
					alreadyPass[this->ganttDiagram[i].first] = true;
				}
				else{

					int lasted = this->ganttDiagram[i-1].second.second;
					int now = this->ganttDiagram[i].second.second;
					cout << setw(now-(lasted+this->ganttDiagram[i-1].second.first)+1);

					for(j=0; j<this->ganttDiagram[i].second.first; j++)
						cout << "|";
				}


				if(i < this->ganttDiagram.size()-1)
					if(this->ganttDiagram[i].first != this->ganttDiagram[i+1].first)
						cout << endl;
			
			}

			delete[] alreadyPass;
		}
		else{

			for(i=0; i<this->ganttDiagram.size(); i++){
				rlutil::setColor(((this->ganttDiagram[i].first-1)%14)+1);

				cout << setw(3) << this->ganttDiagram[i].first << " :";
				cout << setw(3 + this->ganttDiagram[i].second.second);

				for(j=0; j<this->ganttDiagram[i].second.first; j++)
					cout << "|";

				cout << endl;
			}

		}
	}
	else{

		for(i=0; i<this->ganttDiagram.size(); i++){

			rlutil::setColor(((this->ganttDiagram[i].first-1)%14)+1);

			cout << setw(3) << this->ganttDiagram[i].first << " :";
			cout << setw(3+last);
			
			for(j=0; j<this->ganttDiagram[i].second.first; j++)
				cout << "|";
			
			cout << endl;
		
			last += j;
		}

	}


	cout << endl << endl;
	rlutil::setColor(7);

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

	if(this->tclock == 0)
		getchar();
	else
		sleep(this->tclock);
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
		cout << it->getId() << "[" << it->getPriority() << "," << it->getInstIterations() << "] ";
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
