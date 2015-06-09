#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>

using namespace std;


enum STTypes{
	ST_INT, ST_BOOL, ST_FLOAT, ST_CHAR,
	ST_INT_VECTOR, ST_BOOL_VECTOR, ST_DOUBLE_VECTOR, ST_STRING,
	ST_FUNC, ST_VAR, ST_GLOBAL, ST_LOCAL
};

typedef pair<int, int> ii;
typedef pair<string, int> si;

class Node{

	public:

		// id
		string name;
		
		// line number defined
		unsigned int line;

		// 1 - n
		int scope;
		
		// 1: function or variable
		// 2: type
		ii type;

		// if is a function
		map<string, Node> params;


		Node(string name, ii type, int scope, unsigned int line){
			this->name = name;
			this->line = line;
			this->type = type;
			this->scope = scope;
		};

		void addParam(Node *n){
			this->params.insert(pair<string, Node>(n->name, *n));
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

		// scopes
		const static int GLOBAL;
		const static int PARAM;
		const static int LOCAL;

		// unknown type and scope
		const static ii UNKNOWN_TYPE;
		const static int UNKNOWN_SCOPE;

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

const ii SymbolTable::UNKNOWN_TYPE = ii(-1, -1);
const int SymbolTable::UNKNOWN_SCOPE = -1;



// int main(){

// 	SymbolTable *st = new SymbolTable();

// 	Node *n1 = new Node("main", ii(1, 1), 0, 0);
// 	n1->addParam(new Node("argc", ii(0, ST_INT), 1, 0));
// 	n1->addParam(new Node("argv", ii(0, ST_STRING), 1, 0));

// 	st->add(n1);

// 	Node *n = st->get("main");

// 	cout << n->name << endl;
// 	cout << n->type.first << " | " << n->type.second << endl;
// 	cout << n->scope << endl;
	
// 	cout << n->getParam("argc")->name << endl;


// 	delete st;

// 	return 0;
// }