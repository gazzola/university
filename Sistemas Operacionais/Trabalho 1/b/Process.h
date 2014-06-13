typedef unsigned long int uli;
typedef unsigned short int usi;

#define CPUBOUND 0
#define IOBOUND 1

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
		int getRunIterations();
		vector<string> getHistory();
		void setPriority(usi priority);
		void setState(usi state);
		void addHistory(string str);
		void setInstIterations(int instIterations);
		void execute(int moreIterations);
		bool alreadyExecuted();

};