#include "Process.h"

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
