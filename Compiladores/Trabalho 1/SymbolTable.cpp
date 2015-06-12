class Node{

	public:

		// id
		string name;
		
		// line number defined
		unsigned int line;

		// 1 - n
		int scope;
		
		// 1: function, variable, constant, command
		// 2: type
		ii type;

		// dimension
		// 0 -> pointer
		// 1 -> variable
		// n -> array of size n
		int dim;

		// if is a pointer
		Node *pt;

		// if is a function
		map<string, Node> params;

		// attribute value
		// void *value;
		double *value;
		
		// flag for interpreter
		bool setted;


		Node(string name, int dim, ii type, int scope, unsigned int line){
			this->name = name;
			this->line = line;
			this->type = type;
			this->scope = scope;
			this->dim = dim;
			this->setted = false;
			this->value = new double[dim];
			this->pt = NULL;
		};

		// const node
		Node(int dim, ii type){
			this->name = "_constant_";
			this->dim = dim;
			this->type = type;
			this->setted = false;
			this->value = new double[dim];
			this->pt = NULL;
		}


		void setValue(double v){
			this->value[0] = v;
			this->setted = true;
		}

		void setValue(unsigned int i, double v){
			this->value[i] = v;
			this->setted = true;
		}
		
		void setValue(double *v){
			memcpy(this->value, v, this->dim * sizeof(v));
			this->setted = true;
		}

		void setValue(Node *x){
			this->pt = x;
			this->setted = true;
		}


		double getValue(){
			return this->value[0];
		}

		double getValue(unsigned int index){
			if(index >= 0 and index < this->dim)
				return this->value[index];
			semanticError->arrayBound(this->name);
		}

		double* getValueArr(){
			return this->value;
		}

		Node* getPointer(){
			return this->pt;
		}



		string typeToString(){
			string s;
			if(this->type.second == ST_INT)
				s = "int";
			else if(this->type.second == ST_FLOAT)
				s = "float";
			else if(this->type.second == ST_CHAR)
				s = "char";
			else if(this->type.second == ST_BOOL)
				s = "bool";
			else
				s = "undefined";
			return s;
		}


		string functionToString(){
			map<string, Node>::iterator itp;
			string s = "(";
			string t = "";

			for(itp = this->params.begin(); itp != this->params.end(); ++itp)
				t += itp->second.typeToString() + " " + itp->first + ", ";
				
			if(t.size() > 0)
				t[t.size()-2] = ')';
			else
				t = ")";

			return s+t;
		}


		void printValue(int w){

			if(this->setted and this->dim == 1){
				int t = this->type.second;
				if(t == ST_INT)
					cout << setw(w) << (int) this->value[0];
				else if(t == ST_FLOAT)
					cout << setw(w) << (float) this->value[0];
				else if(t == ST_CHAR)
					cout << setw(w) << (char) this->value[0];
				else
					cout << setw(w) << (bool) this->value[0];
			}
			else if(this->setted and this->dim == 0)
				cout << setw(w) << "pointer to " << this->pt->name << endl; 
			else if(this->setted and this->dim > 1)
				cout << setw(w) << "array";
			else
				cout << setw(w) << "undefined";
		}


		bool addParam(Node *n){
			if(this->getParam(n->name) != NULL)
				return false;
			this->params.insert(pair<string, Node>(n->name, *n));
			return true;
		}

		Node* getParam(string name){
			map<string, Node>::iterator it = this->params.find(name);
			if(it != this->params.end())
				return &(*it).second;
			return NULL;
		}

		virtual ~Node(){};
};



class SymbolTable{


	private:
		map<si, Node> tab;
		
	public:

		SymbolTable(){};

		Node* get(string name, int scope){
			map<si, Node>::iterator it = this->tab.find(si(name, scope));
			if(it != this->tab.end())
				return &(*it).second;
			return NULL;
		}

		bool add(Node *n){
			if(this->get(n->name, n->scope) != NULL)
				return false;
			this->tab.insert(pair<si, Node>(si(n->name, n->scope), *n));
			return true;
		}

		virtual ~SymbolTable(){};

		void print(){


			map<si, Node>::iterator it;
			map<string, Node>::iterator itp;
			string s = "";


			cout << left << setw(16) << "NOME:";
			cout << setw(4) << " | ";

			cout << left << setw(36) << "TIPO:";
			cout << setw(4) << " | ";

			cout << left << setw(16) << "DIMENSAO:";
			cout << setw(4) << " | ";

			cout << left << setw(16) << "ESCOPO:";
			cout << setw(4) << " | ";

			cout << left << setw(16) << "VALOR:";
			cout << setw(4) << " | ";

			cout << left << setw(16) << "LINHA:";
			cout << setw(4) << " | ";

			cout << endl;



			for(it = this->tab.begin(); it != this->tab.end(); ++it){
				
				cout << left << setw(16) << it->second.name;
				cout << setw(4) << " | ";


				s = it->second.typeToString() + " ";

				if(it->second.type.first == ST_VAR)
					s += "variable";
				else if(it->second.type.first == ST_FUNC)
					s += "function"+it->second.functionToString();
				else
					s += "const";	

				cout << left << setw(36) << s;
				cout << setw(4) << " | ";


				cout << left << setw(16) << it->second.dim;
				cout << setw(4) << " | "; 


				cout << left << setw(16) << it->second.scope - ST_GLOBAL;
				cout << setw(4) << " | "; 


				it->second.printValue(16);
				cout << setw(4) << " | ";


				cout << left << setw(16) << it->second.line;
				cout << setw(4) << " | "; 
				cout << endl; 

				
			}

		}
};





// int main(){

// 	SymbolTable *st = new SymbolTable();

// 	Node *n1 = new Node("main", 1, ii(1, 1), 1, 0);
// 	n1->addParam(new Node("argc", 1, ii(0, ST_INT), 1, 0));
// 	n1->addParam(new Node("argv", 4, ii(0, ST_CHAR), 1, 0));

// 	st->add(n1);

// 	Node *n = st->get("main", 1);

// 	cout << n->name << endl;
// 	cout << n->type.first << " | " << n->type.second << endl;
// 	cout << n->scope << endl;
	
// 	cout << n->getParam("argc")->name << endl;


// 	n->setValue<int>(25);
// 	cout << n->getValue<int>() << endl;

// 	int x[2] = {3, 5};
// 	int y[2];

// 	n->setArray<int>(x);
// 	memcpy(&y, n->getArray<int>(), sizeof(y));
// 	cout << x[0] << " " << x[1] << endl;

// 	delete st;

// 	return 0;
// }