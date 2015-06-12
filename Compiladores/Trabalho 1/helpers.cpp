
// a = b op c com cast dos tipos genericos T
template <class T>
void assignOperation(Node *a, T v1, T v2, string op){
	if("&")
		a->setValue((T) v1 && (T) v2);
	else if("|")
		a->setValue((T) v1 || (T) v2);
	else if("+")
		a->setValue((T) v1 + (T) v2);
	else if("-")
		a->setValue((T) v1 - (T) v2);
	else if("*")
		a->setValue((T) v1 * (T) v2);
	else if("/"){
		if(v2 == 0)
			printf("\nALERTA: divisao por 0 na linha %d\n", a->line);
		else
			a->setValue((T) v1 / (T) v2);
	}
	else if("<")
		a->setValue((T) v1 < (T) v2);
	else if(">")
		a->setValue((T) v1 > (T) v2);
	else if("<=")
		a->setValue((T) v1 <= (T) v2);
	else if(">=")
		a->setValue((T) v1 >= (T) v2);
	else if("==")
		a->setValue((T) v1 == (T) v2);
	
}


void assignValue(Node *a, Node *b, Node *c, string op){
	if(b->type.second != c->type.second)
		semanticError->incompatible("tipos", b->name, c->name);

	if(b->dim != c->dim)
		semanticError->incompatible("dimensao", b->name, c->name);


	int t = b->type.second;
	if(a->type.first == ST_UNKNOWN)
		a->type = ii(ST_CONST, t);
	a->line = nlines;

	if(t == ST_INT){
		int v1 = b->getValue();
		int v2 = c->getValue();
		assignOperation<int>(a, v1, v2, op);
	}
	else if(t == ST_FLOAT){
		float v1 = b->getValue();
		float v2 = c->getValue();
		assignOperation<float>(a, v1, v2, op);
	}
	else if(t == ST_CHAR){
		char v1 = b->getValue();
		char v2 = c->getValue();
		assignOperation<char>(a, v1, v2, op);
	}
	else if(t == ST_BOOL){
		bool v1 = b->getValue();
		bool v2 = c->getValue();
		assignOperation<bool>(a, v1, v2, op);
	}
	else
		semanticError->incompatible("tipos", b->name, c->name);

}

void appendVector(vector<Node> *v, vector<Node> *t){
	if(t != NULL)
		for(int i=0; i<(int) t->size(); i++)
			v->push_back(t->at(i));
}



void addListaVars(vector<Node> *v){
	for(int i=0; i<(int) v->size(); i++){
		v->at(i).scope = nscopes;
		if(!st->add(&(v->at(i))))
			semanticError->redeclaration("variavel", v->at(i).name);
	}
	delete v;
}


void addFunction(string name, int type){
	if(!st->add(new Node(name, 1, ii(ST_FUNC, type), ST_GLOBAL, nlines)))
		semanticError->redeclaration("funcao", name);
	funcaoatual = st->get(name, ST_GLOBAL);
	tiporetorno = (type == ST_VOID) ? ST_VOID : ST_UNKNOWN;
	nscopes = ++mscope;
}


void addParams(string fname, vector<Node> *v){
	Node *fun = st->get(fname, ST_GLOBAL);
	for(int i=0; i<(int) v->size(); i++){
		v->at(i).scope = nscopes;
		if(!st->add(&(v->at(i))))
			semanticError->redeclaration("parametro", v->at(i).name);
		else
			fun->addParam(&(v->at(i)));
	}
	delete v;
}

void closeFunction(){
	nscopes = ST_GLOBAL;
	if(tiporetorno == ST_UNKNOWN)
		syntaxError->missReturnExpression(funcaoatual->name);
	tiporetorno = ST_UNKNOWN;
	funcaoatual = NULL;
}


void addItem(vector<Node> *v, Node *x){
	v->push_back(*x);
}

vector<Node>* createItemVector(Node *x){
	vector<Node> *v = new vector<Node>();
	addItem(v, x);
	return v;
}

vector<Node>* createItemVector(){
	return new vector<Node>();
}




Node* getNode(string name){
	return (st->get(name, nscopes) != NULL) ? st->get(name, nscopes) : st->get(name, ST_GLOBAL);
}


Node* getPointerOf(Node *x){
	while(x->dim == 0)
		x = x->getPointer();
	return x;
}


void assign(Node *x, Node *y){
	// try to assignOperation
	if(x->type.second == y->type.second){
		if(x->dim == y->dim)
			if(x->dim > 1)
				x->setValue(y->getValueArr());
			else
				x->setValue(y->getValue());
		else
			semanticError->incompatible("dimensoes", x->name, y->name);
	}
	else
		semanticError->incompatible("tipos", x->name, y->name);
}



void assign(Node *x, unsigned int index, Node *y){
	// try to assignOperation
	if(x->type.second == y->type.second){
		if(x->dim == y->dim)
			x->setValue(index, y->getValue());
		else
			semanticError->incompatible("dimensoes", x->name, y->name);
	}
	else
		semanticError->incompatible("tipos", x->name, y->name);
}



void assignExpression(Node *x, Node *y){
	// if is a pointer
	x = getPointerOf(x);
	assign(x, y);
}


void assignExpression(string name, Node *y){

	Node *x = getNode(name);
	if(x != NULL){
		// if is a pointer
		y = getPointerOf(y);
		assign(x, y);
	} 
	else
		semanticError->undeclaration("variavel", name);

}

void assignExpression(string name, unsigned int index, Node *y){
	Node *x = getNode(name);
	if(x != NULL){

		if(index >= 0 and index < x->dim){
			// if is a pointer
			y = getPointerOf(y);

			int t = x->dim;
			x->dim = 1;
			assign(x, index, y);
			x->dim = t;

		}
		else
			semanticError->arrayBound(name);
	} 
	else
		semanticError->undeclaration("variavel", name);
}


Node* createItem(string name, int dim){
	return new Node(name, dim, ii(ST_VAR, tipoatual), ST_UNKNOWN_SCOPE, nlines);
}


Node* getItem(string name, string x){
	Node *n = getNode(name);
	if(n != NULL) 
		return n;
	else 
		semanticError->undeclaration(x, name);
}


Node* getItem(string name, unsigned int index, string x){
	Node *n = getNode(name);
	if(n != NULL){
		if(index >= 0 and index < n->dim){
			Node *y = new Node(n->name, 1, n->type, n->scope, n->line);
			y->setValue(n->getValue());
		}
		else
			semanticError->arrayBound(name);
	}
	else
		semanticError->undeclaration(x, name);
}

Node* createConstNode(int type, double value){
	Node *x = new Node(1, ii(ST_CONST, type)); 
	x->setValue(value);
	return x;
}


void verifyReturn(Node *f, Node *x){
	if(f->type.second != x->type.second)
		semanticError->unexpectedReturnType(f->name);
	else if(f->dim != x->dim)
		semanticError->unexpectedReturnDimension(f->name);

	tiporetorno = x->type.second;
}



string typeToString(int type){
	string s;
	if(type == ST_INT)
		s = "int";
	else if(type == ST_FLOAT)
		s = "float";
	else if(type == ST_CHAR)
		s = "char";
	else if(type == ST_BOOL)
		s = "bool";
	else
		s = "void";
	return s;
}


string functionToString(Node *f){
	return f->typeToString() + " " +  f->name + f->functionToString();
}


string functionToString(Node *f, vector<Node> *params){
	
	string s = f->typeToString() + " " + f->name + "(";
	string t = "";

	for(int i=0; i<(int) params->size(); i++)
		t += params->at(i).typeToString() + " " + params->at(i).name + ", ";

	if(t.size() > 0)
		t[t.size()-2] = ')';
	else
		t = ")";

	return s+t;
}

void verifyParameters(Node *f, vector<Node> *v){
	if(f->params.size() != v->size())
		semanticError->incompatibleParameters("quantidades", functionToString(f), functionToString(f, v));

	map<string, Node>::iterator itp;
	int i = 0;
	for(itp = f->params.begin(); itp != f->params.end(); ++itp){
		if(itp->second.type.second != v->at(i).type.second)
			semanticError->incompatibleParameters("tipos", functionToString(f), functionToString(f, v));
		else if(itp->second.dim != v->at(i).dim)
			semanticError->incompatibleParameters("dimensoes", functionToString(f), functionToString(f, v));
		++i;
	}
}