enum TipoInterrupcoes{
	terminal, impressora, disco, teclado, mouse
};
typedef enum TipoInterrupcoes typeInter;


class Interrupt{

	private:
		int id, action, priority;
		typeInter type;

	public:
		Interrupt(int id, typeInter type, int action, int priority){
			this->id = id;
			this->type = type;
			this->action = action;
			this->priority = priority;
		}

		virtual ~Interrupt(){}


		int getId() const{
			return this->id;
		}

		typeInter getType(){
			return this->type;
		}

		int getAction(){
			return this->action;
		}

		int getPriority() const{
			return this->priority;
		}
};


template <class T>
class InterruptHandler{

	private:
		static InterruptHandler *instance; //singleton pattern
		int qtdInter, idInter;
		bool sortByPriority;
		vector<Interrupt> interruptions;
		void removeInter(int position);
		void sortInterruptions();
		InterruptHandler();
		InterruptHandler(InterruptHandler const&){};             // copy constructor is private
		InterruptHandler& operator=(InterruptHandler const&){};  // assignment operator is private

	public:
		virtual ~InterruptHandler();
		typeInter getTypoByRand();
		int addInter(typeInter type, int action, int priority);	//sleep(action)
		bool handle(int idInter);
		void setSortType(string type);
		static InterruptHandler<T>* getInstance();
};

template <class T>
InterruptHandler<T>* InterruptHandler<T>::instance = NULL;

template <class T>
InterruptHandler<T>::InterruptHandler(){
	this->qtdInter = 0;
	this->idInter = 0;
	this->sortByPriority = true;
}

template <class T>
InterruptHandler<T>::~InterruptHandler(){
	InterruptHandler::instance = NULL;
	this->interruptions.clear();
	//da para fazer mudar para um novo temporario, eh ate melhor desse jeito, 
	//pois libera a posicao de memoria para um proximo acesso
}

template <class T>
InterruptHandler<T>* InterruptHandler<T>::getInstance(){
	if(InterruptHandler::instance == NULL)
		InterruptHandler::instance = new InterruptHandler();
	return InterruptHandler::instance;
}


template <class T>
typeInter InterruptHandler<T>::getTypoByRand(){
	int value = rand()%5;
	if(value == 0)
		return impressora;
	else if(value == 1)
		return terminal;
	else if(value == 2)
		return mouse;
	else if(value == 3)
		return teclado;
	else
		return disco;
}

template <class T>
int InterruptHandler<T>::addInter(typeInter type, int action, int priority){
	T *i = new Interrupt(this->idInter, type, action, priority);
	this->interruptions.push_back(*i);
	this->sortInterruptions();
	int tempId = this->idInter;
	this->qtdInter += 1;
	this->idInter += 1;
	return tempId;
}

template <class T>
void InterruptHandler<T>::removeInter(int position){
	this->interruptions.erase(this->interruptions.begin()+position);
}


bool orderByPriorityInter(const Interrupt &i, const Interrupt &j){
	return (i.getPriority() > j.getPriority());
}

bool orderByFIFOInter(const Interrupt &i, const Interrupt &j){
	return (i.getId() < j.getId());
}


template <class T>
void InterruptHandler<T>::sortInterruptions(){
	if(this->sortByPriority)
		sort(this->interruptions.begin(), this->interruptions.end(), orderByPriorityInter);
	else
		sort(this->interruptions.begin(), this->interruptions.end(), orderByFIFOInter);
}

template <class T>
void InterruptHandler<T>::setSortType(string type){
	this->sortByPriority = (type != "FIFO");
}


template <class T>
bool InterruptHandler<T>::handle(int idInter){

	while(this->interruptions.size() > 0){
		T i = this->interruptions.front();

		cout << "Esperando pela interrupcao " << idInter << " acabar." << endl;
		cout << "INTERRUPCAO ATUAL: " << i.getId() << endl;

		switch(i.getType()){
			case terminal:
				cout << "Interrupcao por terminal." << endl;
				break;

			case impressora:
				cout << "Interrupcao por impressora." << endl;
				break;

			case disco:
				cout << "Interrupcao por disco." << endl;
				break;

			case teclado:
				cout << "Interrupcao por teclado." << endl;
				break;

			case mouse:
				cout << "Interrupcao por mouse." << endl;
				break;
		}

		cout << endl;

		sleep(i.getAction());

		if(i.getId() == idInter)
			return true;

		this->removeInter(0); //first element
	}

	return false; //nao achou a interrupcao
}

