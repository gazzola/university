#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
#include <cassert>
#include <cstring>
#include <iomanip>

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
		
		// flag for interpreter
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
			this->name = "_constant_";
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

		void printValue(int w){

			if(this->setted){
				int t = this->type.second;
				if(t == ST_INT)
					cout << setw(w) << (int) this->value;
				else if(t == ST_FLOAT)
					cout << setw(w) << (float) this->value;
				else if(t == ST_CHAR)
					cout << setw(w) << (char) this->value;
				else
					cout << setw(w) << (bool) this->value;
			}
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



				if(it->second.type.second == ST_INT)
					s = "int ";
				else if(it->second.type.second == ST_FLOAT)
					s = "float ";
				else if(it->second.type.second == ST_CHAR)
					s = "char ";
				else
					s = "bool ";

				if(it->second.type.first == ST_VAR)
					s += "variable";
				else if(it->second.type.first == ST_FUNC){
					string t = "";
					s += "function(";
					string x = "";

					for(itp = it->second.params.begin(); itp != it->second.params.end(); ++itp){
						if(itp->second.type.second == ST_INT)
							x = "int ";
						else if(itp->second.type.second == ST_FLOAT)
							x = "float ";
						else if(itp->second.type.second == ST_CHAR)
							x = "char ";
						else
							x = "bool ";

						t += x + itp->first + ",";
					}
					if(t.size() > 0)
						t[t.size()-1] = ')';
					else
						t = ")";
					s += t;
				}
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