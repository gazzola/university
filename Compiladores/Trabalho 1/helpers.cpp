
// a = b op c com cast dos tipos genericos T
template <class T>
void assign(Node *a, T v1, T v2, string op){
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


void assignValue(Node *a, Node *b, Node *c, string op, unsigned int line){
	if(b->type.second != c->type.second){
		printf("\nERRO SEMANTICO: operacao: '%s' com tipos diferentes! linha:%u\n", op.c_str(), line);
		return;
	}

	int t = b->type.second;
	a->type = ii(ST_CONST, t);
	a->line = line;

	if(t == ST_INT){
		int v1 = b->getValue();
		int v2 = c->getValue();
		assign<int>(a, v1, v2, op);
	}
	else if(t == ST_FLOAT){
		float v1 = b->getValue();
		float v2 = c->getValue();
		assign<float>(a, v1, v2, op);
	}
	else if(t == ST_CHAR){
		char v1 = b->getValue();
		char v2 = c->getValue();
		assign<char>(a, v1, v2, op);
	}
	else if(t == ST_BOOL){
		bool v1 = b->getValue();
		bool v2 = c->getValue();
		assign<bool>(a, v1, v2, op);
	}
	else{
		printf("\nERRO SEMANTICO: operacao '%s' com tipos não conhecidos! linha:%u\n", op.c_str(), line);
	}
}

void appendVector(vector<Node> *v, vector<Node> *t){
	if(t != NULL)
		for(int i=0; i<(int) t->size(); i++)
			v->push_back(t->at(i));
}