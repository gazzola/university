
// a = b op c
template <class T>
void setHelper(Node *a, T v1, T v2, string op){
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
		setHelper<int>(a, v1, v2, op);
	}
	else if(t == ST_FLOAT){
		float v1 = b->getValue();
		float v2 = c->getValue();
		setHelper<float>(a, v1, v2, op);
	}
	else if(t == ST_CHAR){
		char v1 = b->getValue();
		char v2 = c->getValue();
		setHelper<char>(a, v1, v2, op);
	}
	else{
		bool v1 = b->getValue();
		bool v2 = c->getValue();
		setHelper<bool>(a, v1, v2, op);
	}
}

