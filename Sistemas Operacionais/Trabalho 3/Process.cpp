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

int Process::getRunIterations(){
	return this->runIterations;
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
	if(this->type == CPUBOUND)
		instIterations *= 2;
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
