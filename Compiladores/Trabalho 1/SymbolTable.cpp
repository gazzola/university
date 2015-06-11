#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;


typedef pair<int, int> ii;
typedef pair<char, char> cc;
typedef pair<float, float> ff;
typedef pair<bool, bool> bb;

typedef pair<string, int> si;

enum STTypes{
	ST_INT, ST_BOOL, ST_FLOAT, ST_CHAR,
	ST_FUNC, ST_VAR, ST_CONST,  ST_CMD,
	ST_GLOBAL, ST_LOCAL
};

const int ST_UNKNOWN = -1;
const ii UNKNOWN_TYPE = ii(ST_UNKNOWN, ST_UNKNOWN);
const int UNKNOWN_SCOPE = ST_UNKNOWN;


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

		// if is a function
		map<string, Node> params;

		// attribute value
		// void *value;
		double value;
		bool setted;


		Node(string name, int dim, ii type, int scope, unsigned int line){
			this->name = name;
			this->line = line;
			this->type = type;
			this->scope = scope;
			this->dim = dim;
			this->setted = false;
		};

		// const node
		Node(int dim, ii type){
			this->name = "_unknown_";
			this->dim = dim;
			this->type = type;
			this->setted = false;
		}


		void setValue(double v){
			this->value = v;
			this->setted = true;
		}

		
		double getValue(){
			return this->value;
		}

		void printValue(){
			int t = this->type.second;
			if(t == ST_INT){
				printf("%d", (int) this->value);
			}
			else if(t == ST_FLOAT){
				printf("%f", (float) this->value);
			}
			else if(t == ST_CHAR){
				printf("%c", (int) this->value);
			}
			else{
				printf("%d", (bool) this->value);
			}
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