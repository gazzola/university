#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
// #include <iostream>

using namespace std;



typedef pair<int, int> ii;

class Node{

	public:

		string name;
		int scope;
		ii type;
		// 1: function or variable
		// 2: type

		Node(string name, ii type, int scope){
			this->name = name;
			this->type = type;
			this->scope = scope;
		};

		virtual ~Node(){};
};



class SymbolTable{


	private:
		map<string, Node> tab;
		
	public:

		// scopes
		const static int GLOBAL;
		const static int PARAM;
		const static int LOCAL;

		// unknown type and scope
		const static ii UNKNOWN_TYPE;
		const static int UNKNOWN_SCOPE;

		SymbolTable(){};

		Node* get(string name){
			map<string, Node>::iterator it = this->tab.find(name);
			if(it != this->tab.end())
				return &(*it).second;
			return NULL;
		}

		void add(string name, ii type, int scope){
			Node *n1 = new Node(name, type, scope);
			this->tab.insert(pair<string,Node>(name, *n1));
		}


		virtual ~SymbolTable(){};
};

const int SymbolTable::GLOBAL = 0;
const int SymbolTable::PARAM = 1;
const int SymbolTable::LOCAL = 2;
const ii SymbolTable::UNKNOWN_TYPE = ii(-1, -1);
const int SymbolTable::UNKNOWN_SCOPE = -1;



// int main(){

// 	SymbolTable *st = new SymbolTable();
// 	st->add("main", ii(1, 1), 0);
// 	Node *n = st->get("main");

// 	cout << n->name << endl;
// 	cout << n->type.first << " | " << n->type.second << endl;
// 	cout << n->scope << endl;


// 	delete st;

// 	return 0;
// }