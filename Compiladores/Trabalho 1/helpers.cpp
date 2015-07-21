/*
Realiza a atribuição para o nodo a entre dois operandos (v1 e v2) com tipo
genérico T para uma operação op.
---
a = b op c com cast dos tipos genericos T
*/
template <class T>
void assignOperation(Node *a, T v1, T v2, string op){
	if(op == "&")
		a->setValue((T) v1 && (T) v2);
	else if(op == "|")
		a->setValue((T) v1 || (T) v2);
	else if(op == "+")
		a->setValue((T) v1 + (T) v2);
	else if(op == "-")
		a->setValue((T) v1 - (T) v2);
	else if(op == "*")
		a->setValue((T) v1 * (T) v2);
	else if(op == "/"){
		if((T) v2 == 0)
			cout << endl << "WARNING: divisao por 0 na linha " << a->line << endl;
		else
			a->setValue((T) v1 / (T) v2);
	}
	else if(op == "<")
		a->setValue((T) v1 < (T) v2);
	else if(op == ">")
		a->setValue((T) v1 > (T) v2);
	else if(op == "<=")
		a->setValue((T) v1 <= (T) v2);
	else if(op == ">=")
		a->setValue((T) v1 >= (T) v2);
	else if(op == "==")
		a->setValue((T) v1 == (T) v2);
	else if(op == "!=")
		a->setValue((T) v1 != (T) v2);
	else
		syntaxError->unkownOperator(op);
	
}



/*
Realiza a atribuição para o nodo a entre dois operandos que são nodos já
declarados (b e c) para uma operação op. Essa função identifica erros de tipos
no momentos da atribuição. Os erros são identificados pelos tipos e pelas
dimensões desses nodos. Caso deseja-se cancelar a questão de calcular os
valores para cada expressão, basta então comentar as linhar onde a função
assignOperation é chamada.
*/
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



/*
Realiza a concatenação do vetor v e do vetor t.
*/
void appendVector(vector<Node> *v, vector<Node> *t){
	if(t != NULL)
		for(int i=0; i<(int) t->size(); i++)
			v->push_back(t->at(i));
}



/*
Adiciona os nodos que estiverem dentro do vetor v para a tabela de símbolos
caso os mesmos ainda não foram declarados, caso contrário, gera um erro de
redeclaração de variável.
*/
void addListaVars(vector<Node> *v){
	for(int i=0; i<(int) v->size(); i++){
		v->at(i).scope = nscopes;
		if(!st->add(&(v->at(i))))
			semanticError->redeclaration("variavel", v->at(i).name);
	}
	delete v;
}



/*
Adiciona uma função com chamada name com tipo type para a tabela de símbolos
caso os mesmos ainda não foi declarada, caso contrário, gera um erro de
redeclaração de função. Além disso, é incrementado a variável global nscopes
que indica o escopo atual da execução.
*/
void addFunction(string name, int type){
	if(!st->add(new Node(name, 1, ii(ST_FUNC, type), ST_GLOBAL, nlines)))
		semanticError->redeclaration("funcao", name);
	funcaoatual = st->get(name, ST_GLOBAL);
	tiporetorno = (type == ST_VOID) ? ST_VOID : ST_UNKNOWN;
	nscopes = ++mscope;
}



/*
Adiciona os parâmetros que estão no vetor v para a função fname na tabela de
símbolos caso eles ainda não tiverem sido declarados. Caso contrário, é gerado
um erro semântico de redeclaração de parametro.
*/
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



/*
Ao fechar uma função o escopo atual é colocado como sendo o escopo global.
Além disso, esse helper verifica se a função tem um tipo de retorno, onde caso
não tiver é gerado um erro sintático indicando que não há retorno na função
sendo analisada.
*/
void closeFunction(){
	nscopes = ST_GLOBAL;
	if(tiporetorno == ST_UNKNOWN)
		syntaxError->missReturnExpression(funcaoatual->name);
	tiporetorno = ST_UNKNOWN;
	funcaoatual = NULL;
}



/*
Adiciona um nodo x no fim de um vetor de nodos v.
*/
void addItem(vector<Node> *v, Node *x){
	v->push_back(*x);
}



/* 
Cria o vetor de nodos v e já adiciona esse nodo x nele. É retornado esse
vetor v.
*/
vector<Node>* createItemVector(Node *x){
	vector<Node> *v = new vector<Node>();
	addItem(v, x);
	return v;
}



/*
Cria e retorna um vetor vazio de nodos.
*/
vector<Node>* createItemVector(){
	return new vector<Node>();
}



/*
Busca um identificador na tabela de símbolos utilizando o escopo atual
nscopes. Caso não encontre, é buscado no escopo global, caso não encontrem nem
no global então retornado NULL.
*/
Node* getNode(string name){
	return (st->get(name, nscopes) != NULL) ? st->get(name, nscopes) : st->get(name, ST_GLOBAL);
}



/*
Busca o ponteiro do nodo x, esse helper só é utilizado para questões de
atribuição de valores.
*/
Node* getPointerOf(Node *x){
	while(x->dim == 0)
		x = x->getPointer();
	return x;
}



/*
Realiza a atribuição de um nodo y para um nodo x (x = y). Isso é feito apenas
se os tipos e as dimensões de ambos nodos forem iguais. Caso contrário é
gerado um erro semântico indicando o erro de incompatibilidade de tipo ou
dimensão.
*/
void assign(Node *x, Node *y){
	// try to assign
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



/*
Realiza a atribuição de um nodo y para um nodo x (x[index] = y). Isso é feito
apenas se os tipos e as dimensões de ambos nodos forem compatíveis. Caso
contrário é gerado um erro semântico indicando o erro de incompatibilidade de
tipo ou dimensão.
*/
void assign(Node *x, unsigned int index, Node *y){
	// try to assign
	if(x->type.second == y->type.second){
		if(x->dim == y->dim)
			x->setValue(index, y->getValue());
		else
			semanticError->incompatible("dimensoes", x->name, y->name);
	}
	else
		semanticError->incompatible("tipos", x->name, y->name);
}



/*
Realiza a atribuição de uma expressão y para uma expressão y.
*/
void assignExpression(Node *x, Node *y){
	// if is a pointer
	x = getPointerOf(x);
	assign(x, y);
}



/*
Busca a instância do identificador name na tabela de símbolos e realização a
atribuição de y para esse identificador. Caso a instância do identificador
seja nula, significa que aquela variável ainda não foi declarada e é gerado um
erro semântico indicando isso.
*/
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



/*
Busca a instância do identificador name na tabela de símbolos e realização a
atribuição de y para esse identificador na posição index (isso significa que a
instância retornada deve ser um nodo com dimensão maior ou igual a 1) caso o
valor do índice seja compatível com as dimensões do identificador name. Caso
essa dimensão seja incompatível, significa que o está tentando acessar uma
posição do vetor que vai além dos limites do vetor e então é gerado um erro
semântico indicando isso. Assim como o helper anterior, essa atribuição é
feito apenas se o identificador já foi declarado na tabela de símbolos.
*/
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



/*
Cria a instância de um nodo com nome name, dimensão dim, tipo como a tupla
(variável e tipo atual sendo analisado), escopo indefinido e linha de
declaração. Essa instância é então retornada.
*/
Node* createItem(string name, int dim){
	return new Node(name, dim, ii(ST_VAR, tipoatual), ST_UNKNOWN_SCOPE, nlines);
}



/*
Busca um nodo na tabela de símbolos e o retorna caso não seja NULL, caso
contrário gera um erro semântico indicando que o identificador não foi
declarado.
*/
Node* getItem(string name, string x){
	Node *n = getNode(name);
	if(n != NULL) 
		return n;
	else 
		semanticError->undeclaration(x, name);
}



/*
Busca um nodo na tabela de símbolo e retorna um novo nodo com o valor que
corresponde sendo esse nodo na posição index. Um erro semântico é gerado caso
a dimensão do nodo buscado não seja compátivel com o nodo buscado. Além disso,
um erro semântico é gerado caso o retorno da tabela de símbolos seja NULL,
indicando que o identificador não foi declarado.
*/
Node* getItem(string name, unsigned int index, string x){
	Node *n = getNode(name);
	if(n != NULL){
		if(index >= 0 and index < n->dim){
			Node *y = new Node(n->name, 1, n->type, n->scope, n->line);
			y->setValue(n->getValue());
			return y;
		}
		else
			semanticError->arrayBound(name);
	}
	else
		semanticError->undeclaration(x, name);
}



/* 
Cria um nodo constante de dimensão 1, tipo type e valor value. Esse nodo é
então retornado.
*/

Node* createConstNode(int type, double value){
	Node *x = new Node(1, ii(ST_CONST, type)); 
	x->setValue(value);
	return x;
}



/*
Verifica se o tipo e a dimensão do retorna da função f é igual ao da expressão
de retorno x. Caso seja, a variável global tiporetorno é definido como sendo o
tipo da expressão de retorno. Caso dê incompatibilidade no tipo ou na
dimensão, é gerado um erro semântico indicando essa incompatibilidade.
*/
void verifyReturn(Node *f, Node *x){
	if(f->type.second != x->type.second)
		semanticError->unexpectedReturnType(f->name);
	else if(f->dim != x->dim)
		semanticError->unexpectedReturnDimension(f->name);

	tiporetorno = x->type.second;
}



/*
Função que auxilia no momentar de imprimir a tabela de símbolos, ela recebe um
tipo type e retorna uma string correspondente para aquele tipo, indicando qual
tipo é. Essa string é então retornada.
*/
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



/*
Concatena a assinatura da função: tipo nome. Essa concatenação é feita numa
string, que é então retornada.
*/
string functionToString(Node *f){
	return f->typeToString() + " " +  f->name + f->functionToString();
}



/*
Utiliza a função anterior e aproveita concatena os parâmetros que estão no
vetor params na string de saída. De modo que fique: tipo nome (tipo1 param1, tipo2 param2, ...).
*/
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



/*
Verifica se os tipos dos parâmetros (tipo e dimensão) de uma chamada da função
f são compatíveis com os tipos dos parâmetros da declaração dessa função. Caso
não seja, é gerado um erro semântico indicando o erro.
*/
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