#define CRIADO 0
#define PRONTO 1
#define PRONTOSUS 2
#define BLOQUEADO 3
#define BLOQUEADOSUS 4
#define EXECUTANDO 5
#define ENCERRADO 6
#define MAX_PRONTO 4
#define MAX_BLOQUEADO 4

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